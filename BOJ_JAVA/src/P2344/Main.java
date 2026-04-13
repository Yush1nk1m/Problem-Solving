package P2344;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M, number;
    static int[][] table;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        table = new int[N + 2][M + 2];
        for (int r = 1; r <= N; ++r)
            table[r][0] = ++number;
        for (int c = 1; c <= M; ++c)
            table[N + 1][c] = ++number;
        for (int r = N; r >= 1; --r)
            table[r][M + 1] = ++number;
        for (int c = M; c >= 1; --c)
            table[0][c] = ++number;

        for (int r = 1; r <= N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 1; c <= M; ++c)
                table[r][c] = Integer.parseInt(st.nextToken());
        }
    }

    private static void solve() {
        for (int r = 1; r <= N; ++r)
            sb.append(findExit(r, 1, 0, 1)).append(' ');
        for (int c = 1; c <= M; ++c)
            sb.append(findExit(N, c, -1, 0)).append(' ');
        for (int r = N; r >= 1; --r)
            sb.append(findExit(r, M, 0, -1)).append(' ');
        for (int c = M; c >= 1; --c)
            sb.append(findExit(1, c, 1, 0)).append(' ');

        System.out.print(sb);
    }

    private static int findExit(int r, int c, int dr, int dc) {
        while (isValidPoint(r, c)) {
            if (table[r][c] == 1) {
                int t = -dr;
                dr = -dc;
                dc = t;
            }
            r += dr;
            c += dc;
        }
        return table[r][c];
    }

    private static boolean isValidPoint(int r, int c) {
        return 1 <= r && r <= N && 1 <= c && c <= M;
    }
}
