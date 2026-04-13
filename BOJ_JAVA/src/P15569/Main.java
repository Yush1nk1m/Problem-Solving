package P15569;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;
    static final int MOD = 1999;

    static int N, M, base;
    static int[] rowCache, cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        cache = new int[M + 1];
        rowCache = new int[N + 1];
        Arrays.fill(cache, NONE);
        Arrays.fill(rowCache, NONE);
    }

    private static void solve() {
        base = DFSForBase(N);
        System.out.print(DFS(M));
    }

    private static int DFSForBase(int length) {
        if (length == 0)
            return 1;
        else if (length < 0)
            return 0;
        else if (rowCache[length] != NONE)
            return rowCache[length];

        rowCache[length] = 0;
        for (int l = 1; l < N; ++l) {
            rowCache[length] += DFSForBase(length - l);
            rowCache[length] %= MOD;
        }
        return rowCache[length];
    }

    private static int DFS(int length) {
        if (length == 0)
            return 1;
        else if (length < 0)
            return 0;
        else if (cache[length] != NONE)
            return cache[length];

        cache[length] = (base * DFS(length - N)) % MOD;
        for (int l = 1; l <= N; ++l) {
            cache[length] += DFS(length - l);
            cache[length] %= MOD;
        }
        return cache[length];
    }
}
