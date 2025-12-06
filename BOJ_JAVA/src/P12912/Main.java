package P12912;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge {
        int from, to;
        long cost;

        public Edge(int from, int to, long cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, from, to;
    static long cost;
    static List<Edge>[] graph;
    static List<Edge> edgeList = new ArrayList<>();
    static boolean[][] connected;
    static boolean[] visited;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        graph = new List[N];
        for (int i = 0; i < N; ++i)
            graph[i] = new ArrayList<>();
        connected = new boolean[N][N];
        visited = new boolean[N];
        parent = new int[N];
        for (int i = 0; i < N - 1; ++i) {
            tokens = br.readLine().split(" ");
            from = Integer.parseInt(tokens[0]);
            to = Integer.parseInt(tokens[1]);
            cost = Long.parseLong(tokens[2]);
            graph[from].add(new Edge(from, to, cost));
            graph[to].add(new Edge(to, from, cost));
            connected[from][to] = connected[to][from] = true;
            edgeList.add(new Edge(from, to, cost));
        }
        System.out.println(solve());
    }

    static long solve() {
        long diameter = 0;
        for (Edge edge : edgeList) {
            initializeVariables();
            removeEdge(edge);
            DFS(edge.from);
            DFS(edge.to);
            int root1 = edge.from;
            while (root1 != parent[root1])
                root1 = parent[root1];
            int root2 = edge.to;
            while (root2 != parent[root2])
                root2 = parent[root2];
            initializeVariables();
            diameter = Math.max(diameter, edge.cost + DFS(root1) + DFS(root2));
            recoverEdge(edge);
        }
        return diameter;
    }

    static void initializeVariables() {
        for (int i = 0; i < N; ++i) {
            visited[i] = false;
            parent[i] = i;
        }
    }

    static void removeEdge(Edge edge) {
        connected[edge.from][edge.to] = connected[edge.to][edge.from] = false;
    }

    static void recoverEdge(Edge edge) {
        connected[edge.from][edge.to] = connected[edge.to][edge.from] = true;
    }

    static long DFS(int root) {
        visited[root] = true;

        long distance = 0L;
        for (Edge edge : graph[root])
            if (connected[edge.from][edge.to] && !visited[edge.to]) {
                long ret = edge.cost + DFS(edge.to);
                if (ret > distance) {
                    distance = ret;
                    parent[root] = edge.to;
                }
            }

        return distance;
    }
}
