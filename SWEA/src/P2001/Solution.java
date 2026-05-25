package P2001;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N, M;
    static int[][] table;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; ++t) {
            initialize();
            solve(t);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        table = new int[N + 1][N + 1];

        for (int r = 1; r <= N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 1; c <= N; ++c)
                table[r][c] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; ++i) {
            table[i][1] += table[i - 1][1];
            table[1][i] += table[1][i - 1];
        }
        for (int r = 2; r <= N; ++r)
            for (int c = 2; c <= N; ++c)
                table[r][c] += table[r - 1][c] + table[r][c - 1] - table[r - 1][c - 1];
    }

    private static void solve(int t) {
        sb.append('#').append(t).append(' ');
        int sum = 0;
        for (int r = M; r <= N; ++r)
            for (int c = M; c <= N; ++c)
                sum = Math.max(sum, table[r][c] - table[r - M][c] - table[r][c - M] + table[r - M][c - M]);
        sb.append(sum).append('\n');
    }
}
