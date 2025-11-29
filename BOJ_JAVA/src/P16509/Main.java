package P16509;

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

    static final int dr[] = new int[]{-3, -2, 2, 3, 3, 2, -2, -3};
    static final int dc[] = new int[]{2, 3, 3, 2, -2, -3, -3, -2};
    static final int drs[][] = new int[][]{
            {-1, -2}, {0, -1}, {0, 1}, {1, 2}, {1, 2}, {0, 1}, {0, -1}, {-1, -2}
    };
    static final int dcs[][] = new int[][]{
            {0, 1}, {1, 2}, {1, 2}, {0, 1}, {0, -1}, {-1, -2}, {-1, -2}, {0, -1}
    };

    static int sr, sc, er, ec, step;
    static final boolean[][] visited = new boolean[10][9];
    static final Queue<Coords> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        sr = Integer.parseInt(tokens[0]);
        sc = Integer.parseInt(tokens[1]);
        tokens = br.readLine().split(" ");
        er = Integer.parseInt(tokens[0]);
        ec = Integer.parseInt(tokens[1]);

        visited[sr][sc] = true;
        queue.add(new Coords(sr, sc));
        while (!queue.isEmpty() && !visited[er][ec]) {
            ++step;
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                for (int d = 0; d < 8; ++d) {
                    int nr = curr.r + dr[d], nc = curr.c + dc[d];
                    if (!isValidPoint(nr, nc) || isColliding(curr.r, curr.c, d) || visited[nr][nc])
                        continue;
                    visited[nr][nc] = true;
                    queue.offer(new Coords(nr, nc));
                }
            }
        }

        if (!visited[er][ec])
            System.out.println(-1);
        else
            System.out.println(step);
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < 10 && 0 <= c && c < 9;
    }

    public static boolean isColliding(int r, int c, int i) {
        int[] dr = drs[i], dc = dcs[i];
        for (int d = 0; d < 2; ++d)
            if (r + dr[d] == er && c + dc[d] == ec)
                return true;
        return false;
    }
}
