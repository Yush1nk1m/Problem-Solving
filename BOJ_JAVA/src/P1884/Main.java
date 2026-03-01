package P1884;

import java.io.*;
import java.util.*;

public class Main {

    static class Road {
        int source, destination, length, toll;

        public Road(int source, int destination, int length, int toll) {
            this.source = source;
            this.destination = destination;
            this.length = length;
            this.toll = toll;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;
    static final int INF = 100_000_000;

    static int K, N, R;
    static List<Road>[] graph;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        K = Integer.parseInt(br.readLine());
        N = Integer.parseInt(br.readLine());
        R = Integer.parseInt(br.readLine());

        graph = new List[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList<>();

        while (R-- > 0) {
            tokens = br.readLine().split(" ");
            int source = Integer.parseInt(tokens[0]);
            int destination = Integer.parseInt(tokens[1]);
            int length = Integer.parseInt(tokens[2]);
            int toll = Integer.parseInt(tokens[3]);
            graph[source].add(new Road(source, destination, length, toll));
        }

        cache = new int[N + 1][K + 1];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static int solve() {
        return DFS(1, K) == INF ? -1 : DFS(1, K);
    }

    private static int DFS(int node, int budget) {
        if (budget < 0)
            return INF;
        else if (node == N)
            return 0;
        else if (cache[node][budget] != NONE)
            return cache[node][budget];

        cache[node][budget] = INF;
        for (Road road : graph[node])
            cache[node][budget] = Math.min(cache[node][budget], road.length + DFS(road.destination, budget - road.toll));

        return cache[node][budget];
    }
}
