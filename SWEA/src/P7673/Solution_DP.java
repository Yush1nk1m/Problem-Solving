package P7673;

import java.io.*;
import java.util.*;

public class Solution_DP {

    static class Info {
        int m2, m5;

        public Info(int m2, int m5) {
            this.m2 = m2;
            this.m5 = m5;
        }

        public static Info build(int number) {
            if (number == 0) return null;
            int m2 = 0, m5 = 0;
            while (number % 2 == 0 && number > 0) {
                number >>= 1;
                ++m2;
            }
            while (number % 5 == 0 && number > 0) {
                number /= 5;
                ++m5;
            }
            return new Info(m2, m5);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final Info INF = new Info(100_000_000, 100_000_000);

    static final int[] dr = {1, 0};
    static final int[] dc = {0, 1};

    static int T, N;
    static Info[][] table, cache;
    static boolean[][] expanded;

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
        table = new Info[N][N];
        cache = new Info[N][N];
        expanded = new boolean[N][N];

        for (int r = 0; r < N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < N; ++c)
                table[r][c] = Info.build(Integer.parseInt(st.nextToken()));
        }
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        Info info = DFS(0, 0);
        sb.append(Math.min(info.m2, info.m5)).append('\n');
    }

    private static Info DFS(int r, int c) {
        if (r == N - 1 && c == N - 1)
            return table[r][c];
        else if (cache[r][c] != null)
            return cache[r][c];

        cache[r][c] = INF;
        if (r + 1 < N && table[r][c] != null) {
            Info ret = DFS(r + 1, c);
            if (Math.min(cache[r][c].m2, cache[r][c].m5) > Math.min(ret.m2 + table[r][c].m2, ret.m5 + table[r][c].m5))
                cache[r][c] = new Info(ret.m2 + table[r][c].m2, ret.m5 + table[r][c].m5);
        }
        if (c + 1 < N && table[r][c] != null) {
            Info ret = DFS(r, c + 1);
            if (Math.min(cache[r][c].m2, cache[r][c].m5) > Math.min(ret.m2 + table[r][c].m2, ret.m5 + table[r][c].m5))
                cache[r][c] = new Info(ret.m2 + table[r][c].m2, ret.m5 + table[r][c].m5);
        }

        return cache[r][c];
    }
}
