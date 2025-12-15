package P31863;

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

    static final char SOURCE = '@';
    static final char WALL = '|';
    static final char WEAK = '*';
    static final char STRONG = '#';

    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static int N, M, buildings, collapsed;
    static char[][] table;
    static int[][] count;
    static Queue<Coords> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        table = new char[N][];
        count = new int[N][M];
        for (int r = 0; r < N; ++r) {
            table[r] = br.readLine().toCharArray();
            for (int c = 0; c < M; ++c) {
                if (table[r][c] == SOURCE)
                    queue.offer(new Coords(r, c));
                else if (table[r][c] == WEAK) {
                    count[r][c] = 1;
                    ++buildings;
                }
                else if (table[r][c] == STRONG) {
                    count[r][c] = 2;
                    ++buildings;
                }
            }
        }
        while (!queue.isEmpty()) {
            Coords curr = queue.poll();
            for (int d = 0; d < 4; ++d) {
                int nr = curr.r + dr[d], nc = curr.c + dc[d];
                if (!isValidPoint(nr, nc))
                    continue;
                if (--count[nr][nc] == 0) {
                    queue.offer(new Coords(nr, nc));
                    ++collapsed;
                }
                if (table[curr.r][curr.c] == SOURCE) {
                    nr += dr[d];
                    nc += dc[d];
                    if (!isValidPoint(nr, nc))
                        continue;
                    if (--count[nr][nc] == 0) {
                        queue.offer(new Coords(nr, nc));
                        ++collapsed;
                    }
                }
            }
        }
        System.out.println(collapsed + " " + (buildings - collapsed));
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M && table[r][c] != WALL;
    }
}
