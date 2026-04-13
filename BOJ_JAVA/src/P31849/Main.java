package P31849;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static int N, M, R, C, a, b, p, c, d;
    static int[][] table;
    static boolean[][] visited;
    static Queue<Coords> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        R = Integer.parseInt(tokens[2]);
        C = Integer.parseInt(tokens[3]);

        table = new int[N + 1][M + 1];
        visited = new boolean[N + 1][M + 1];

        while (R-- > 0) {
            tokens = br.readLine().split(" ");
            a = Integer.parseInt(tokens[0]);
            b = Integer.parseInt(tokens[1]);
            p = Integer.parseInt(tokens[2]);
            table[a][b] = p;
        }

        while (C-- > 0) {
            tokens = br.readLine().split(" ");
            c = Integer.parseInt(tokens[0]);
            d = Integer.parseInt(tokens[1]);
            visited[c][d] = true;
            queue.offer(new Coords(c, d));
        }
    }

    private static void solve() {
        int minScore = Integer.MAX_VALUE;
        int distance = 0;

        while (!queue.isEmpty()) {
            ++distance;
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                for (int d = 0; d < 4; ++d) {
                    int r = curr.r + dr[d], c = curr.c + dc[d];
                    if (!isValidPoint(r, c) || visited[r][c])
                        continue;

                    visited[r][c] = true;
                    queue.offer(new Coords(r, c));
                    if (table[r][c] > 0)
                        minScore = Math.min(minScore, distance * table[r][c]);
                }
            }
        }

        System.out.print(minScore);
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 < r && r <= N && 0 < c && c <= M;
    }
}
