package P1266;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final double NONE = -1.0;

    static int T;
    static Double p1, p2;
    static boolean[] isPrime = new boolean[19];
    static double[][][] cache = new double[19][19][19];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = isPrime[11] = isPrime[13] = isPrime[17] = true;

        st = new StringTokenizer(br.readLine());
        p1 = Double.parseDouble(st.nextToken()) / 100.0;
        p2 = Double.parseDouble(st.nextToken()) / 100.0;

        for (double[][] mat : cache)
            for (double[] vec : mat)
                Arrays.fill(vec, NONE);
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        String probability = String.format("%.6f", DFS(0, 0, 0));
        sb.append(probability).append('\n');
    }

    private static double DFS(int i, int o1, int o2) {
        if (i == 18)
            return isPrime[o1] || isPrime[o2] ? 1.0 : 0.0;
        else if (cache[i][o1][o2] != NONE)
            return cache[i][o1][o2];

        return cache[i][o1][o2] =
                p1 * p2 * DFS(i + 1, o1 + 1, o2 + 1) +
                        p1 * (1.0 - p2) * DFS(i + 1, o1 + 1, o2) +
                        (1.0 - p1) * p2 * DFS(i + 1, o1, o2 + 1) +
                        (1.0 - p1) * (1.0 - p2) * DFS(i + 1, o1, o2);
    }
}
