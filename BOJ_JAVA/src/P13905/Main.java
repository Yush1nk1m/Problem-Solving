package P13905;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int src, dest, weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        public int compareTo(Edge other) {
            return Integer.compare(other.weight, weight);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, s, e, h1, h2, k;
    static int[] parent;
    static PriorityQueue<Edge> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        parent = new int[N + 1];
        for (int i = 1; i <= N; ++i)
            parent[i] = i;

        tokens = br.readLine().split(" ");
        s = Integer.parseInt(tokens[0]);
        e = Integer.parseInt(tokens[1]);

        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            h1 = Integer.parseInt(tokens[0]);
            h2 = Integer.parseInt(tokens[1]);
            k = Integer.parseInt(tokens[2]);
            pq.offer(new Edge(h1, h2, k));
        }
    }

    private static void solve() {
        int weight = 0;
        while (!pq.isEmpty() && !find(s, e)) {
            Edge edge = pq.poll();
            if (!find(edge.src, edge.dest)) {
                union(edge.src, edge.dest);
                weight = edge.weight;
            }
        }
        if (!find(s, e))
            weight = 0;
        System.out.print(weight);
    }

    private static boolean find(int n1, int n2) {
        while (parent[n1] != n1)
            n1 = parent[n1];
        while (parent[n2] != n2)
            n2 = parent[n2];
        return n1 == n2;
    }

    private static void union(int n1, int n2) {
        List<Integer> list = new ArrayList<>();
        while (parent[n1] != n1) {
            list.add(n1);
            n1 = parent[n1];
        }

        while (parent[n2] != n2) {
            list.add(n2);
            n2 = parent[n2];
        }
        list.add(n2);

        for (int node : list)
            parent[node] = n1;
    }
}
