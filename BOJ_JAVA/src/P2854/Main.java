package P2854;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final long MOD = 1_000_000_007L;
    static final long NONE = -1L;

    static int N;
    static long[] known, unknown;
    static long[][] cache;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        cache = new long[N][2];
        for (long[] row : cache)
            Arrays.fill(row, NONE);
        known = new long[N];
        unknown = new long[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            known[i] = Long.parseLong(tokens[i]);
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N - 1; ++i)
            unknown[i] = Long.parseLong(tokens[i]);
        System.out.println(DFS(0, 0));
    }

    public static long DFS(int level, int selected) {
        if (level == N)
            return 1L;
        else if (cache[level][selected] != NONE)
            return cache[level][selected];

        if (selected == 1) {
            return cache[level][selected] =
                    ((DFS(level + 1, 0) % MOD) + (unknown[level] * DFS(level + 1, 1)) % MOD) % MOD;
        }

        cache[level][selected] = known[level] * DFS(level + 1, 0);
        cache[level][selected] %= MOD;
        cache[level][selected] += unknown[level] * DFS(level + 1, 0);
        cache[level][selected] %= MOD;
        cache[level][selected] += ((known[level] * unknown[level]) % MOD) * DFS(level + 1, 1);
        cache[level][selected] %= MOD;
        cache[level][selected] += ((unknown[level] * (unknown[level] - 1)) % MOD) * DFS(level + 1, 1);
        cache[level][selected] %= MOD;

        return cache[level][selected];
    }
}
