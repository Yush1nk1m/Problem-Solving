package P20010;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int node1, node2, cost;

        public Edge(int node1, int node2, int cost) {
            this.node1 = node1;
            this.node2 = node2;
            this.cost = cost;
        }

        public int compareTo(Edge other) {
            return Integer.compare(cost, other.cost);
        }
    }

    static class Info {
        int node, cost;

        public Info(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, K;
    static List<Edge>[] graph;
    static int[] parent;
    static boolean[] visited;
    static PriorityQueue<Edge> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);

        graph = new List[N];
        for (int i = 0; i < N; ++i)
            graph[i] = new ArrayList<>();
        parent = new int[N];
        for (int i = 0; i < N; ++i)
            parent[i] = i;
        visited = new boolean[N];

        while (K-- > 0) {
            tokens = br.readLine().split(" ");
            pq.offer(new Edge(
                    Integer.parseInt(tokens[0]),
                    Integer.parseInt(tokens[1]),
                    Integer.parseInt(tokens[2])
            ));
        }

        sb.append(MST()).append('\n').append(getDiameter());
        System.out.print(sb);
    }

    public static boolean find(int node1, int node2) {
        while (node1 != parent[node1])
            node1 = parent[node1];
        while (node2 != parent[node2])
            node2 = parent[node2];

        return node1 == node2;
    }

    public static void union(int node1, int node2) {
        List<Integer> nodes = new ArrayList<>();

        while (node1 != parent[node1]) {
            nodes.add(node1);
            node1 = parent[node1];
        }

        while (node2 != parent[node2]) {
            nodes.add(node2);
            node2 = parent[node2];
        }
        nodes.add(node2);

        for (int node : nodes)
            parent[node] = node1;
    }

    public static int MST() {
        int total = 0, count = N - 1;
        while (!pq.isEmpty() && count > 0) {
            Edge edge = pq.poll();
            if (find(edge.node1, edge.node2))
                continue;
            union(edge.node1, edge.node2);
            graph[edge.node1].add(new Edge(edge.node1, edge.node2, edge.cost));
            graph[edge.node2].add(new Edge(edge.node2, edge.node1, edge.cost));
            total += edge.cost;
            --count;
        }
        return total;
    }

    public static int getDiameter() {
        Info info = DFS(1);
        Arrays.fill(visited, false);
        return DFS(info.node).cost;
    }

    public static Info DFS(int root) {
        visited[root] = true;

        Info curr = new Info(root, 0);
        for (Edge edge : graph[root]) {
            if (visited[edge.node2])
                continue;

            Info next = DFS(edge.node2);
            if (curr.cost < next.cost + edge.cost) {
                curr.node = next.node;
                curr.cost = next.cost + edge.cost;
            }
        }

        return curr;
    }
}
