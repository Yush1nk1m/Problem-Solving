package P24887;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final long NONE = -1L;

    static int N;
    static long M, maxValue;
    static long[] W, cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Long.parseLong(tokens[1]);
        W = new long[N];
        cache = new long[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i) {
            W[i] = Long.parseLong(tokens[i]);
            maxValue = Math.max(maxValue, W[i]);
        }
        if (maxValue >= M)
            System.out.println("Free!");
        else
            System.out.println(solve());
    }

    public static int solve() {
        int l = 1, h = N - 1, ret = 0;
        while (l <= h) {
            int m = (l + h) >> 1;
            Arrays.fill(cache, NONE);
            if (DFS(0, m) >= M) {
                ret = Math.max(ret, m);
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ret - 1;
    }

    public static long DFS(int i, int k) {
        if (i >= N)
            return 0;
        else if (cache[i] != NONE)
            return cache[i];

        return cache[i] = Math.max(DFS(i + 1, k), W[i] + DFS(i + k, k));
    }
}
