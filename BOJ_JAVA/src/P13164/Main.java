package P13164;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, K;
    static long[] height, gap;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);

        height = new long[N];
        gap = new long[N - 1];

        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            height[i] = Long.parseLong(tokens[i]);
        for (int i = 0; i < N - 1; ++i)
            gap[i] = height[i + 1] - height[i];
    }

    private static void solve() {
        Arrays.sort(gap);
        for (int i = 1; i < N - 1; ++i)
            gap[i] += gap[i - 1];
        if (N == K)
            System.out.print(0);
        else
            System.out.print(gap[N - K - 1]);
    }
}
