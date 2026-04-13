package P33926;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int r, c;
        long value;

        public Node(int r, int c, long value) {
            this.r = r;
            this.c = c;
            this.value = value;
        }

        public int compareTo(Node other) {
            return Long.compare(other.value, value);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int BLACK = 1;
    static final int MIN = 0;
    static final int MAX = 1;

    static int N, M;
    static long[][][] table;
    static int[][] color;
    static PriorityQueue<Node> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        table = new long[2][N][M];
        color = new int[N][M];

        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < M; ++c)
                table[MIN][r][c] = table[MAX][r][c] = Long.parseLong(tokens[c]);
        }

        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < M; ++c)
                color[r][c] = Integer.parseInt(tokens[c]);
        }
    }

    private static void solve() {
        for (int r = 1; r < N; ++r) {
            table[MIN][r][0] += table[MIN][r - 1][0];
            table[MAX][r][0] += table[MAX][r - 1][0];
            if (color[r][0] == BLACK) {
                table[MIN][r][0] = -table[MIN][r][0];
                table[MAX][r][0] = -table[MAX][r][0];
            }
        }

        for (int c = 1; c < M; ++c) {
            table[MIN][0][c] += table[MIN][0][c - 1];
            table[MAX][0][c] += table[MAX][0][c - 1];
            if (color[0][c] == BLACK) {
                table[MIN][0][c] = -table[MIN][0][c];
                table[MAX][0][c] = -table[MAX][0][c];
            }
        }

        for (int r = 1; r < N; ++r)
            for (int c = 1; c < M; ++c) {
                if (color[r][c] == BLACK) {
                    table[MIN][r][c] = -(Math.max(table[MAX][r - 1][c], table[MAX][r][c - 1]) + table[MIN][r][c]);
                    table[MAX][r][c] = -(Math.min(table[MIN][r - 1][c], table[MIN][r][c - 1]) + table[MAX][r][c]);
                } else {
                    table[MIN][r][c] = Math.min(table[MIN][r - 1][c], table[MIN][r][c - 1]) + table[MIN][r][c];
                    table[MAX][r][c] = Math.max(table[MAX][r - 1][c], table[MAX][r][c - 1]) + table[MAX][r][c];
                }
            }

        System.out.print(table[MAX][N - 1][M - 1]);
    }
}
