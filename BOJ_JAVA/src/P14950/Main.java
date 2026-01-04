package P14950;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int source, destination, cost;

        public Edge(int source, int destination, int cost) {
            this.source = source;
            this.destination = destination;
            this.cost = cost;
        }

        public int compareTo(Edge other) {
            return Integer.compare(cost, other.cost);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, t, total;
    static int[] parent;
    static List<Edge> edgeList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        t = Integer.parseInt(tokens[2]);

        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            edgeList.add(new Edge(
                    Integer.parseInt(tokens[0]),
                    Integer.parseInt(tokens[1]),
                    Integer.parseInt(tokens[2])
            ));
        }
        Collections.sort(edgeList);

        parent = new int[N + 1];
        for (int i = 1; i <= N; ++i)
            parent[i] = i;

        for (Edge edge : edgeList)
            if (!find(edge.source, edge.destination)) {
                union(edge.source, edge.destination);
                total += edge.cost;
            }
        total += (t * (N - 1) * (N - 2)) >> 1;

        System.out.print(total);
    }

    public static boolean find(int n1, int n2) {
        while (n1 != parent[n1])
            n1 = parent[n1];

        while (n2 != parent[n2])
            n2 = parent[n2];

        return n1 == n2;
    }

    public static void union(int n1, int n2) {
        List<Integer> list = new ArrayList<>();

        while (n1 != parent[n1]) {
            list.add(n1);
            n1 = parent[n1];
        }

        while (n2 != parent[n2]) {
            list.add(n2);
            n2 = parent[n2];
        }
        list.add(n2);

        for (int node : list)
            parent[node] = n1;
    }
}
