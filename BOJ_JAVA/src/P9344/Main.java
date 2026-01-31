package P9344;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int source, destination, weight;

        public Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }

        public int compareTo(Edge other) {
            return Integer.compare(weight, other.weight);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int T, N, M, p, q;
    static int[] parent = new int[10001];
    static PriorityQueue<Edge> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            pq.clear();
            for (int i = 1; i <= 10000; ++i)
                parent[i] = i;
            tokens = br.readLine().split(" ");
            N = Integer.parseInt(tokens[0]);
            M = Integer.parseInt(tokens[1]);
            p = Integer.parseInt(tokens[2]);
            q = Integer.parseInt(tokens[3]);
            while (M-- > 0) {
                tokens = br.readLine().split(" ");
                pq.offer(new Edge(
                        Integer.parseInt(tokens[0]),
                        Integer.parseInt(tokens[1]),
                        Integer.parseInt(tokens[2])
                ));
            }
            sb.append((solve() ? "YES\n" : "NO\n"));
        }
        System.out.print(sb);
    }

    public static boolean solve() {
        int count = N - 1;
        while (count > 0) {
            Edge edge = pq.poll();
            if (find(edge.source, edge.destination))
                continue;
            if ((p == edge.source && q == edge.destination) || (p == edge.destination && q == edge.source))
                return true;
            union(edge.source, edge.destination);
            --count;
        }
        return false;
    }

    public static boolean find(int v1, int v2) {
        while (v1 != parent[v1])
            v1 = parent[v1];
        while (v2 != parent[v2])
            v2 = parent[v2];
        return v1 == v2;
    }

    public static void union(int v1, int v2) {
        List<Integer> nodes = new ArrayList<>();
        while (v1 != parent[v1]) {
            nodes.add(v1);
            v1 = parent[v1];
        }
        while (v2 != parent[v2]) {
            nodes.add(v2);
            v2 = parent[v2];
        }
        nodes.add(v2);
        for (int node : nodes)
            parent[node] = v1;
    }
}
