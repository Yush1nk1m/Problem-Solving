package P27314;

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

    static final char HANBYEOL = 'H';
    static final char PERSON = 'P';
    static final char EXIT = '#';
    static final char WALL = 'X';

    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static int N, M, maxPresents;
    static char[][] maze;
    static boolean[][] visited;
    static Coords hanbyeol;
    static List<Coords> exits = new ArrayList<>();
    static Queue<Coords> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        visited = new boolean[N][M];
        maze = new char[N][];
        for (int r = 0; r < N; ++r) {
            maze[r] = br.readLine().toCharArray();
            for (int c = 0; c < M; ++c)
                if (maze[r][c] == EXIT)
                    exits.add(new Coords(r, c));
        }
        for (Coords coords : exits)
            maxPresents = Math.max(maxPresents, BFS(coords));
        System.out.println(maxPresents);
    }

    public static int BFS(Coords exit) {
        int count = 0;
        boolean found = false;

        queue.clear();
        for (boolean[] row : visited)
            Arrays.fill(row, false);

        queue.offer(exit);
        while (!queue.isEmpty() && !found) {
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                for (int d = 0; d < 4; ++d) {
                    int nr = curr.r + dr[d], nc = curr.c + dc[d];
                    if (!isValidPoint(nr, nc))
                        continue;

                    visited[nr][nc] = true;
                    queue.offer(new Coords(nr, nc));

                    if (maze[nr][nc] == HANBYEOL)
                        found = true;
                    else if (maze[nr][nc] == PERSON)
                        ++count;
                }
            }
        }

        return found ? count : 0;
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M && maze[r][c] != WALL && !visited[r][c];
    }
}
