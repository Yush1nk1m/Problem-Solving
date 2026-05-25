package P1859;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static long[] price, maximum;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        price = new long[N + 1];
        maximum = new long[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            price[i] = maximum[i] = Long.parseLong(st.nextToken());
        for (int i = N - 1; i >= 0; --i)
            maximum[i] = Math.max(maximum[i], maximum[i + 1]);
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        long benefit = 0;
        for (int i = 0; i < N - 1; ++i)
            benefit += Math.max(0L, maximum[i + 1] - price[i]);
        sb.append(benefit).append('\n');
    }
}
