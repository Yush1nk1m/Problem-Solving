package P25343;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;

    static int N;
    static int[][] table;
    static int[][][] cache;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        table = new int[N][N];
        cache = new int[N][N][10001];
        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; ++c) {
                table[r][c] = Integer.parseInt(tokens[c]);
                Arrays.fill(cache[r][c], NONE);
            }
        }
        System.out.println(DFS(0, 0, 0));
    }

    public static int DFS(int r, int c, int max) {
        if (r >= N || c >= N)
            return 0;
        else if (cache[r][c][max] != NONE)
            return cache[r][c][max];

        cache[r][c][max] = Math.max(DFS(r, c + 1, max), DFS(r + 1, c, max));
        if (table[r][c] > max)
            cache[r][c][max] = Math.max(cache[r][c][max], Math.max(1 + DFS(r, c + 1, table[r][c]), 1 + DFS(r + 1, c, table[r][c])));
        return cache[r][c][max];
    }
}
