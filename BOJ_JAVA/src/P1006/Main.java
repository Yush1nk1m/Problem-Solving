package P1006;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int INF = 100_001;

    static int T, N, W, result;
    static int[][] map;
    static int[][][] cache;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0)
            sb.append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        map = new int[2][N + 1];
        cache = new int[2][2][N];
        for (int i = 0; i < 2; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++)
                map[i][j] = Integer.parseInt(st.nextToken());
            map[0][N] = map[0][0]; map[1][N] = map[1][0];
        }

        result = Integer.MAX_VALUE;
        int t00 = map[0][0], t10 = map[1][0], t0n = map[0][N - 1], t1n = map[1][N - 1];
        if (map[0][0] + map[0][N - 1] <= W) {
            cleanCache();
            map[0][0] = map[0][N - 1] = map[0][N] = INF;
            result = Math.min(result, 1 + DFS(1, 0, 0));
            map[0][0] = map[0][N] = t00; map[0][N - 1] = t0n;
        }
        if (map[1][0] + map[1][N - 1] <= W) {
            cleanCache();
            map[1][0] = map[1][N - 1] = map[1][N] = INF;
            result = Math.min(result, 1 + DFS(0, 0, 1));
            map[1][0] = map[1][N] = t10; map[1][N - 1] = t1n;
        }
        if (map[0][0] + map[0][N - 1] <= W && map[1][0] + map[1][N - 1] <= W) {
            cleanCache();
            map[0][0] = map[0][N - 1] = map[0][N] = map[1][0] = map[1][N - 1] = map[1][N] = INF;
            result = Math.min(result, 2 + DFS(0, 1, 0));
            map[0][0] = map[0][N] = t00; map[1][0] = map[1][N] = t10; map[0][N - 1] = t0n; map[1][N - 1] = t1n;
        }
        cleanCache();
        map[0][N] = map[1][N] = INF;
        result = Math.min(result, DFS(0, 0, 0));

        return result;
    }

    /**
     * @param prev: represents the previous cell's pattern
     *            0: only that cell
     *            1: that cell and horizontally adjacent cell
     */
    public static int DFS(int h, int w, int prev) {
        if (w >= N)
            return 0;
        else if (cache[prev][h][w] != INF)
            return cache[prev][h][w];

        int nh = 1 - h, nw = h == 0 ? w : w + 1;
        // select pattern 1
        cache[prev][h][w] = Math.min(cache[prev][h][w], (map[h][w] <= W ? 1 : 0) + DFS(prev != 1 ? nh : h, prev != 1 ? nw : w + 1, 0));
        // select pattern 2
        if (prev != 1 && h == 0 && map[0][w] + map[1][w] <= W)
            cache[prev][h][w] = Math.min(cache[prev][h][w], 1 + DFS(h, w + 1, 0));
        // select pattern 3
        if (map[h][w] + map[h][w + 1] <= W) {
            if (prev == 1)
                cache[prev][h][w] = Math.min(cache[prev][h][w], 1 + DFS(1 - h, h == 0 ? w + 1 : w + 2, 0));
            else
                cache[prev][h][w] = Math.min(cache[prev][h][w], 1 + DFS(1 - h, h == 0 ? w : w + 1, 1));
        }

        return cache[prev][h][w];
    }

    public static void cleanCache() {
        for (int[][] matrix : cache)
            for (int[] row : matrix)
                Arrays.fill(row, INF);
    }
}
