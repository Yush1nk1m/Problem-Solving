package P32715;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, K, ret;
    static int[][] rows, cols;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(br.readLine());
        rows = new int[N + 1][M + 1];
        cols = new int[N + 1][M + 1];
        for (int r = 1; r <= N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 1; c <= M; ++c) {
                rows[r][c] = cols[r][c] = Integer.parseInt(tokens[c - 1]);
                rows[r][c] += rows[r - 1][c];
                cols[r][c] += cols[r][c - 1];
            }
        }

        for (int r = K + 1; r <= N - K; ++r)
            for (int c = K + 1; c <= M - K; ++c)
                if ((rows[r + K][c] - rows[r - K - 1][c] == cols[r][c + K] - cols[r][c - K - 1]) && (cols[r][c + K] - cols[r][c - K - 1]) == (K << 1) + 1)
                    ++ret;

        System.out.println(ret);
    }
}
