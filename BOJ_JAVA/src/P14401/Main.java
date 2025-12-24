package P14401;

import java.io.*;
import java.util.*;

class Main {

    static class Coords {
        int x, y;

        public Coords(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public long getDistance(Coords other) {
            return (long) Math.pow((long) (x - other.x), 2) + (long) Math.pow((long) (y - other.y), 2);
        }

        public static boolean checkStraight(Coords c1, Coords c2, Coords c3) {
            if (!(c1.x <= c2.x && c2.x <= c3.x && c1.y <= c2.y && c2.y <= c3.y))
                return false;
            long x1 = (long) (c2.x - c1.x);
            long x2 = (long) (c3.x - c2.x);
            long y1 = (long) (c2.y - c1.y);
            long y2 = (long) (c3.y - c2.y);
            return x1 * y2 == x2 * y1;
        }
    }

    static class Edge implements Comparable<Edge> {
        int source, destination;
        long cost;

        public Edge(int source, int destination, long cost) {
            this.source = source;
            this.destination = destination;
            this.cost = cost;
        }

        public int compareTo(Edge other) {
            return Long.compare(other.cost, cost);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int n, m, connected;
    static Coords[] coords;
    static List<Edge> edgeList = new ArrayList<>();
    static int[] parent;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        m = Integer.parseInt(tokens[1]);
        coords = new Coords[n + 1];
        parent = new int[n + 1];
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        for (int i = 1; i <= n; ++i) {
            tokens = br.readLine().split(" ");
            coords[i] = new Coords(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
        }
        for (int i = 0; i < m; ++i) {
            tokens = br.readLine().split(" ");
            int u = Integer.parseInt(tokens[0]);
            int v = Integer.parseInt(tokens[1]);
            if (!find(u, v)) {
                ++connected;
                union(u, v);
            }
        }
        initializeEdgeList();
        System.out.print(solve());
    }

    public static boolean find(int u, int v) {
        while (u != parent[u])
            u = parent[u];
        while (v != parent[v])
            v = parent[v];
        return u == v;
    }

    public static void union(int u, int v) {
        List<Integer> list = new ArrayList<>();
        while (u != parent[u]) {
            list.add(u);
            u = parent[u];
        }
        while (v != parent[v]) {
            list.add(v);
            v = parent[v];
        }
        list.add(v);

        for (int node : list)
            parent[node] = u;
    }

    public static void initializeEdgeList() {
        for (int u = 1; u < n; ++u)
            for (int v = u + 1; v <= n; ++v) {
                boolean valid = true;
                for (int m = 1; m <= n; ++m)
                    if (m != u && m != v && Coords.checkStraight(coords[u], coords[m], coords[v])) {
                        valid = false;
                        break;
                    }
                if (valid)
                    edgeList.add(new Edge(u, v, coords[u].getDistance(coords[v])));

            }
        Collections.sort(edgeList);
    }

    public static long solve() {
        long totalCost = 0;
        for (Edge edge : edgeList) {
            if (find(edge.source, edge.destination))
                continue;
            union(edge.source, edge.destination);
            totalCost += edge.cost;
            if (++connected == n - 1)
                return totalCost;
        }
        return totalCost;
    }
}
