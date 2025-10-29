package P31675;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final long NONE = -1L;

    static int N;
    static long sum, sub;
    static long[] R, cache;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        R = new long[N + 1];
        cache = new long[N + 1];
        Arrays.fill(cache, NONE);

        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            sum += R[i] = Long.parseLong(tokens[i]);
        R[N] = R[N - 1];
        sub = Math.min(DFS(0), DFS(1));
        System.out.println(sum - sub);
    }

    public static long DFS(int i) {
        if (i >= R.length)
            return 0L;
        else if (cache[i] != NONE)
            return cache[i];

        return cache[i] = R[i] + Math.min(DFS(i + 2), DFS(i + 3));
    }
}
