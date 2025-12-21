package P32284;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords {
        int x, y;

        public Coords(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int[] dx = new int[]{-1, 0, 1, 0};
    static int[] dy = new int[]{0, -1, 0, 1};
    static char[] mark = new char[]{'S', 'E', 'N', 'W'};

    static int N, M;
    static Coords you;
    static char[][] table;
    static boolean[][] visited;
    static Queue<Coords> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        table = new char[N][M];
        visited = new boolean[N][M];
        tokens = br.readLine().split(" ");
        you = new Coords(
                Integer.parseInt(tokens[0]),
                Integer.parseInt(tokens[1])
        );

        table[you.x][you.y] = 'E';
        visited[you.x][you.y] = true;
        queue.offer(you);
        while (!queue.isEmpty()) {
            Coords curr = queue.poll();
            for (int d = 0; d < 4; ++d) {
                int nx = curr.x + dx[d], ny = curr.y + dy[d];
                if (!isValidPoint(nx, ny) || visited[nx][ny])
                    continue;

                table[nx][ny] = mark[d];
                visited[nx][ny] = true;
                queue.offer(new Coords(nx, ny));
            }
        }

        for (char[] row : table)
            sb.append(row).append('\n');
        System.out.print(sb);
    }

    public static boolean isValidPoint(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < M;
    }
}
