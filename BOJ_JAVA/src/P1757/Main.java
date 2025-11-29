package P1757;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;
    static final int INF = 100_000_001;

    static int N, M;
    static int[] D;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        D = new int[N];
        cache = new int[M][N];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
        for (int i = 0; i < N; ++i)
            D[i] = Integer.parseInt(br.readLine());
        System.out.println(DFS(0, 0));
    }

    public static int DFS(int stamina, int minute) {
        if (minute == N)
            return stamina == 0 ? 0 : -INF;
        else if (minute > N)
            return -INF;
        else if (stamina == M)
            return DFS(0, minute + stamina);
        else if (cache[stamina][minute] != NONE)
            return cache[stamina][minute];

        cache[stamina][minute] = D[minute] + DFS(stamina + 1, minute + 1);
        if (stamina == 0)
            cache[stamina][minute] = Math.max(cache[stamina][minute], DFS(0, minute + 1));
        else
            cache[stamina][minute] = Math.max(cache[stamina][minute], DFS(0, minute + stamina));

        return cache[stamina][minute];
    }
}
