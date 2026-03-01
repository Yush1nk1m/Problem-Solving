package P26259;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int WALL = -100_000_000;
    static final int INF = 100_000_000;

    static int N, M, x1, y1, x2, y2;
    static int[][] table;

    public static void main(String[] args) throws IOException {
        if (!initialize())
            System.out.println("Entity");
        else
            System.out.print(solve());
    }

    private static boolean initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        table = new int[(N << 1) + 1][(M << 1) + 1];
        for (int r = 1; r < (N << 1); r += 2) {
            tokens = br.readLine().split(" ");
            for (int c = 1; c < (M << 1); c += 2)
                table[r][c] = Integer.parseInt(tokens[c >> 1]);
        }
        tokens = br.readLine().split(" ");
        y1 = Integer.parseInt(tokens[0]);
        x1 = Integer.parseInt(tokens[1]);
        y2 = Integer.parseInt(tokens[2]);
        x2 = Integer.parseInt(tokens[3]);
        if (x1 > x2) { int t = x1; x1 = x2; x2 = t; }
        if (y1 > y2) { int t = y1; y1 = y2; y2 = t; }
        if ((x1 == 0 && x2 == M && y1 != 0 && y1 != N) ||
                (y1 == 0 && y2 == N && x1 != 0 && x1 != M))
            return false;
        for (int r = y1 << 1; r <= y2 << 1; ++r)
            for (int c = x1 << 1; c <= x2 << 1; ++c)
                table[r][c] = WALL;
        return true;
    }

    private static int solve() {
        int t;

        for (t = 3; t < N << 1 && table[t - 1][1] != WALL; t += 2)
            table[t][1] += table[t - 2][1];
        while (t < N << 1) {
            table[t][1] = -INF;
            t += 2;
        }

        for (t = 3; t < M << 1 && table[1][t - 1] != WALL; t += 2)
            table[1][t] += table[1][t - 2];
        while (t < M << 1) {
            table[1][t] = -INF;
            t += 2;
        }

        for (int r = 3; r <= N << 1; r += 2)
            for (int c = 3; c <= M << 1; c += 2) {
                int base = table[r][c];
                table[r][c] = -INF;
                if (table[r - 1][c] != WALL)
                    table[r][c] = Math.max(table[r][c], base + table[r - 2][c]);
                if (table[r][c - 1] != WALL)
                    table[r][c] = Math.max(table[r][c], base + table[r][c - 2]);
            }

        return table[(N << 1) - 1][(M << 1) - 1];
    }
}
