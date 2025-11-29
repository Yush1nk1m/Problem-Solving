package P9311;

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
    static String line;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static final char START = 'S';
    static final char WALL = 'X';
    static final char EXIT = 'G';

    static int T, R, C, ret;
    static char[][] maze;
    static Coords startPoint;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            tokens = br.readLine().split(" ");
            R = Integer.parseInt(tokens[0]);
            C = Integer.parseInt(tokens[1]);
            maze = new char[R + 2][C + 2];
            for (char[] row : maze)
                Arrays.fill(row, WALL);
            for (int r = 1; r <= R; ++r) {
                line = br.readLine();
                for (int c = 1; c <= C; ++c)
                    if ((maze[r][c] = line.charAt(c - 1)) == START)
                        startPoint = new Coords(r, c);
            }
            if ((ret = solve()) != NONE)
                sb.append("Shortest Path: ").append(ret).append('\n');
            else
                sb.append("No Exit\n");
        }
        System.out.println(sb);
    }

    public static int solve () {
        int distance = 0;
        boolean[][] visited = new boolean[R + 2][C + 2];
        Queue<Coords> queue = new LinkedList<>();

        visited[startPoint.r][startPoint.c] = true;
        queue.offer(startPoint);
        while (!queue.isEmpty()) {
            int size = queue.size();
            ++distance;
            while (size-- > 0) {
                Coords curr = queue.poll();
                for (int d = 0; d < 4; ++d) {
                    int nr = curr.r + dr[d], nc = curr.c + dc[d];
                    if (visited[nr][nc])
                        continue;
                    visited[nr][nc] = true;
                    if (maze[nr][nc] == EXIT)
                        return distance;
                    else if (maze[nr][nc] != WALL)
                        queue.offer(new Coords(nr, nc));
                }
            }
        }
        return NONE;
    }
}
