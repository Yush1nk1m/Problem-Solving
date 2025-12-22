package P12793;

import java.io.*;
import java.util.*;

class Main {

    static class Coords {
        int x, y;

        public Coords(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final char BLOCK = 'B';
    static final char EMPTY = '.';

    static final int[] ax = new int[]{-1, 0, 1, 0};
    static final int[] ay = new int[]{0, -1, 0, 1};

    static int N, M, K, id, dx, dy, x, y;
    static char[][] board;
    static int[][] idBoard;
    static boolean[][] visited;
    static boolean[] broken;

    public static void main(String[] args) throws IOException {
        processInput();
        assignId();
        System.out.print(solve());
    }

    public static void processInput() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        K = (int) (Double.parseDouble(tokens[2]) * 2);
        board = new char[M << 1 + 1][];
        idBoard = new int[M << 1 + 1][N << 1 + 1];
        visited = new boolean[M << 1 + 1][N << 1 + 1];
        for (int y = M << 1; y >= 0; --y)
            board[y] = br.readLine().toCharArray();
    }

    public static void assignId() {
        for (int y = 1; y <= M << 1; y += 2)
            for (int x = 1; x <= N << 1; x += 2)
                if (!visited[y][x] && board[y][x] == BLOCK)
                    BFS(new Coords(x, y), id++);
        broken = new boolean[id];
    }

    public static void BFS(Coords start, int id) {
        Queue<Coords> queue = new LinkedList<>();

        idBoard[start.y][start.x] = id;
        visited[start.y][start.x] = true;
        queue.offer(start);
        while (!queue.isEmpty()) {
            Coords curr = queue.poll();
            for (int d = 0; d < 4; ++d) {
                int x = curr.x + ax[d], y = curr.y + ay[d];
                if (!isValidPoint(x, y))
                    continue;
                idBoard[y][x] = id;
                visited[y][x] = true;
                queue.offer(new Coords(x, y));
            }
        }
    }

    public static boolean isValidPoint(int x, int y) {
        return 0 <= x && x <= N << 1 && 0 <= y && y <= M << 1 && !visited[y][x] && (board[y][x] == EMPTY || board[y][x] == BLOCK);
    }

    public static int solve() {
        int count = 0;

        dx = -1;
        dy = 1;
        x = K;

        do {
            count += move();
        } while (y != 0);

        return count;
    }

    public static int move() {
        int ret = 0;

        if (board[y][x] == BLOCK && !broken[idBoard[y][x]]) {
            broken[idBoard[y][x]] = true;
            ++ret;
        }
        if (board[y + dy][x] == BLOCK && !broken[idBoard[y + dy][x]]) {
            broken[idBoard[y + dy][x]] = true;
            ++ret;
        }
        if (board[y][x + dx] == BLOCK && !broken[idBoard[y][x + dx]]) {
            broken[idBoard[y][x + dx]] = true;
            ++ret;
        }
        if (board[y + dy][x + dx] == BLOCK && !broken[idBoard[y + dy][x + dx]]) {
            broken[idBoard[y + dy][x + dx]] = true;
            ++ret;
        }

        y += dy;
        x += dx;

        if (x == 0 || x == N << 1)
            dx = -dx;
        if (y == M << 1)
            dy = -dy;

        return ret;
    }
}
