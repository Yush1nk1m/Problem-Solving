package P13911;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge {
        int destination, weight;

        public Edge(int destination, int weight) {
            this.destination = destination;
            this.weight = weight;
        }
    }

    static class Node implements Comparable<Node> {
        int id, distance;

        public Node(int id, int distance) {
            this.id = id;
            this.distance = distance;
        }

        public int compareTo(Node other) {
            return Integer.compare(distance, other.distance);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 1_000_000_000;

    static int V, E, M, x, S, y, u, v, w;
    static List<Edge>[] graph;
    static boolean[] unable;
    static List<Integer> mc = new ArrayList<>(), st = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    public static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        V = Integer.parseInt(tokens[0]);
        E = Integer.parseInt(tokens[1]);

        graph = new List[V + 1];
        for (int i = 1; i <= V; ++i)
            graph[i] = new ArrayList<>();
        unable = new boolean[V + 1];

        while (E-- > 0) {
            tokens = br.readLine().split(" ");
            u = Integer.parseInt(tokens[0]);
            v = Integer.parseInt(tokens[1]);
            w = Integer.parseInt(tokens[2]);
            graph[u].add(new Edge(v, w));
            graph[v].add(new Edge(u, w));
        }

        tokens = br.readLine().split(" ");
        M = Integer.parseInt(tokens[0]);
        x = Integer.parseInt(tokens[1]);
        tokens = br.readLine().split(" ");
        for (int i = 0; i < M; ++i) {
            int node = Integer.parseInt(tokens[i]);
            mc.add(node);
            unable[node] = true;
        }

        tokens = br.readLine().split(" ");
        S = Integer.parseInt(tokens[0]);
        y = Integer.parseInt(tokens[1]);
        tokens = br.readLine().split(" ");
        for (int i = 0; i < S; ++i) {
            int node = Integer.parseInt(tokens[i]);
            st.add(node);
            unable[node] = true;
        }
    }

    public static int solve() {
        int[] mcDistance = dijkstra(mc, x);
        int[] stDistance = dijkstra(st, y);
        int distance = INF;
        for (int i = 1; i <= V; ++i)
            if (!unable[i] && mcDistance[i] <= x && stDistance[i] <= y)
                distance = Math.min(distance, mcDistance[i] + stDistance[i]);

        return distance == INF ? -1 : distance;
    }

    public static int[] dijkstra(List<Integer> startPoints, int bound) {
        boolean[] expanded = new boolean[V + 1];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[] distance = new int[V + 1];
        Arrays.fill(distance, INF);

        for (int point : startPoints) {
            distance[point] = 0;
            pq.offer(new Node(point, distance[point]));
        }

        while (!pq.isEmpty()) {
            Node node = pq.poll();
            if (expanded[node.id])
                continue;
            expanded[node.id] = true;

            for (Edge edge : graph[node.id])
                if (distance[edge.destination] > edge.weight + distance[node.id]) {
                    distance[edge.destination] = distance[node.id] + edge.weight;
                    pq.offer(new Node(edge.destination, distance[edge.destination]));
                }
        }

        return distance;
    }
}
