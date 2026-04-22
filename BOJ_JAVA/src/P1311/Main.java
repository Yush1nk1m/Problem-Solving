package P1311;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int NONE = -1;

    static int N;
    static int[][] graph, cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        graph = new int[N][N];
        cache = new int[N][1 << N];

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; ++j)
                graph[i][j] = Integer.parseInt(st.nextToken());
        }
        for (int[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static void solve() {
        System.out.print(DFS(0, 0));
    }

    private static int DFS(int person, int scheduled) {
        if (scheduled == (1 << N) - 1)
            return 0;
        else if (cache[person][scheduled] != NONE)
            return cache[person][scheduled];

        cache[person][scheduled] = Integer.MAX_VALUE;
        for (int job = 0; job < N; ++job)
            if ((scheduled & (1 << job)) == 0)
                cache[person][scheduled] = Math.min(
                        cache[person][scheduled],
                        graph[person][job] + DFS(person + 1, scheduled | (1 << job)));

        return cache[person][scheduled];
    }
}
