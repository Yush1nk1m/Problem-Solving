package P28017;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = 100_000_000;

    static int N, M;
    static int[][] time, cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        time = new int[N + 1][M + 1];
        cache = new int[N + 1][M + 1];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
        for (int r = 1; r <= N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 1; c <= M; ++c)
                time[r][c] = Integer.parseInt(tokens[c - 1]);
        }
        System.out.println(DFS(0, 0));
    }

    public static int DFS(int round, int weapon) {
        if (round > N)
            return 0;
        else if (cache[round][weapon] != NONE)
            return cache[round][weapon];

        for (int next = 1; next <= M; ++next)
            if (next != weapon)
                cache[round][weapon] = Math.min(cache[round][weapon], DFS(round + 1, next));
        return cache[round][weapon] += time[round][weapon];
    }
}
