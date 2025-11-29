package P1937;

import java.io.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static int n, maxStep;
    static int[][] table, cache;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        table = new int[n][n];
        cache = new int[n][n];
        for (int r = 0; r < n; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < n; ++c)
                table[r][c] = Integer.parseInt(tokens[c]);
        }

        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                maxStep = Math.max(maxStep, DFS(r, c));

        System.out.println(maxStep);
    }

    public static int DFS(int r, int c) {
        if (cache[r][c] != 0)
            return cache[r][c];

        cache[r][c] = 1;
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (!isValidPoint(nr, nc) || table[nr][nc] <= table[r][c])
                continue;
            cache[r][c] = Math.max(cache[r][c], 1 + DFS(nr, nc));
        }
        return cache[r][c];
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    }
}
