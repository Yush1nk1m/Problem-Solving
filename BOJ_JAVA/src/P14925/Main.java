package P14925;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int M, N, L;
    static int[][] table, cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        M = Integer.parseInt(tokens[0]);
        N = Integer.parseInt(tokens[1]);
        table = new int[M][N];
        cache = new int[M][N];
        for (int r = 0; r < M; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; ++c)
                table[r][c] = Integer.parseInt(tokens[c]);
        }
        for (int r = 0; r < M; ++r) {
            cache[r][0] = table[r][0] == 0 ? 1 : 0;
            L = Math.max(L, cache[r][0]);
        }
        for (int c = 0; c < N; ++c) {
            cache[0][c] = table[0][c] == 0 ? 1 : 0;
            L = Math.max(L, cache[0][c]);
        }
        for (int r = 1; r < M; ++r)
            for (int c = 1; c < N; ++c) {
                if (table[r][c] != 0)
                    cache[r][c] = 0;
                else
                    cache[r][c] = 1 + Math.min(cache[r-1][c-1], Math.min(cache[r-1][c], cache[r][c-1]));
                L = Math.max(L, cache[r][c]);
            }
        System.out.println(L);
    }
}
