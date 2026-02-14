package P33561;

import java.io.*;
import java.util.*;

public class Main2 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;


    static int N, K;
    static int[][] value, zero;
    static int[] d;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    public static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        value = new int[N + 1][N + 1];
        zero = new int[N + 1][N + 1];

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

    public static int solve() {
        int ret = 0;
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                for (int size = Math.min(N - r, N - c); size > 0; --size) {
                    int zeroCount = zero[r][c] - zero[r + size][c] - zero[r][c + size] + zero[r + size][c + size];
                    int valueSum = value[r][c] - value[r + size][c] - value[r][c + size] + value[r + size][c + size];
                    if (zeroCount <= K)
                        ret = Math.max(ret, valueSum + d[zeroCount]);
                }
        return ret;
    }
}
