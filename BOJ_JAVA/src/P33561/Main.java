package P33561;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;

    static int N, K;
    static int[][] value, zero;
    static int[][][] cache;
    static int[] d;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(DFS(0, 0, N));
    }

    public static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        value = new int[N + 1][N + 1];
        zero = new int[N + 1][N + 1];
        cache = new int[N][N][N + 1];

        for (int[][] mat : cache)
            for (int[] row : mat)
                Arrays.fill(row, NONE);

        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; ++c) {
                value[r][c] = Integer.parseInt(tokens[c]);
                zero[r][c] = value[r][c] == 0 ? 1 : 0;
            }
        }

        for (int r = N - 1; r >= 0; --r)
            for (int c = N - 1; c >= 0; --c) {
                value[r][c] += value[r + 1][c] + value[r][c + 1] - value[r + 1][c + 1];
                zero[r][c] += zero[r + 1][c] + zero[r][c + 1] - zero[r + 1][c + 1];
            }

        K = Integer.parseInt(br.readLine());
        tokens = br.readLine().split(" ");
        d = new int[K + 1];
        for (int i = 1; i <= K; ++i)
            d[i] = -Integer.parseInt(tokens[i - 1]);
        Arrays.sort(d, 1, d.length);
        for (int i = 1; i <= K; ++i)
            d[i] = -d[i] + d[i - 1];
    }

    public static int DFS(int r, int c, int size) {
        if (size == 0 || r >= N || c >= N)
            return 0;
        else if (cache[r][c][size] != NONE)
            return cache[r][c][size];

        int zeroCount = zero[r][c] - zero[r + size][c] - zero[r][c + size] + zero[r + size][c + size];
        int valueSum = value[r][c] - value[r + size][c] - value[r][c + size] + value[r + size][c + size];
        if (zeroCount <= K)
            return cache[r][c][size] = valueSum + d[zeroCount];
        else
            return cache[r][c][size] = Math.max(
                    Math.max(
                            DFS(r, c, size - 1),
                            DFS(r + 1, c + 1, size - 1)
                    ),
                    Math.max(
                            DFS(r + 1, c, size - 1),
                            DFS(r, c + 1, size - 1)
                    ));
    }
}
