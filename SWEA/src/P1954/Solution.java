package P1954;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static final int BLOCKED = -1;

    static int T, N;
    static int[][] table;

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
        table = new int[N + 2][N + 2];
        for (int i = 0; i < N + 1; ++i)
            table[i][0] = table[0][i] = table[i][N + 1] = table[N + 1][i] = BLOCKED;
    }

    private static void solve(int x) {
        sb.append('#').append(x).append('\n');

        int r = 1, c = 0, mark = 1;
        while (table[r][c + 1] != BLOCKED && table[r][c + 1] == 0) {
            while (table[r][c + 1] != BLOCKED && table[r][c + 1] == 0)
                table[r][++c] = mark++;
            while (table[r + 1][c] != BLOCKED && table[r + 1][c] == 0)
                table[++r][c] = mark++;
            while (table[r][c - 1] != BLOCKED && table[r][c - 1] == 0)
                table[r][--c] = mark++;
            while (table[r - 1][c] != BLOCKED && table[r - 1][c] == 0)
                table[--r][c] = mark++;
        }

        for (r = 1; r <= N; ++r) {
            for (c = 1; c <= N; ++c)
                sb.append(table[r][c]).append(' ');
            sb.append('\n');
        }
    }
}
