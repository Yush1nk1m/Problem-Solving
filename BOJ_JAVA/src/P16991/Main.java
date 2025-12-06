package P16991;

import java.io.*;
import java.util.*;

class Main {

    static class Coords {
        double x, y;

        public Coords(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public double getDistance(Coords other) {
            return Math.sqrt(Math.pow(x - other.x, 2.0) + Math.pow(y - other.y, 2.0));
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final double NONE = -1.0;
    static final double INF = 100_000_000.0;

    static int N;
    static double x, y;
    static Coords[] coords;
    static double[][] graph, cache;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        cache = new double[N + 1][1 << N];
        for (double[] row : cache)
            Arrays.fill(row, NONE);
        graph = new double[N][N];
        coords = new Coords[N];
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            coords[i] = new Coords(Double.parseDouble(tokens[0]), Double.parseDouble(tokens[1]));
        }
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                graph[r][c] = coords[r].getDistance(coords[c]);
        System.out.println(DFS(0, 1));
    }

    public static double DFS(int prev, int visited) {
        if (visited == (1 << N) - 1)
            return graph[prev][0];
        else if (cache[prev][visited] != NONE)
            return cache[prev][visited];

        cache[prev][visited] = INF;
        for (int next = 0; next < N; ++next)
            if ((visited & (1 << next)) == 0)
                cache[prev][visited] = Math.min(cache[prev][visited], graph[prev][next] + DFS(next, visited | (1 << next)));

        return cache[prev][visited];
    }
}
