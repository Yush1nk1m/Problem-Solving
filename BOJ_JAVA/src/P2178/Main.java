package P2178;

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, M, distance;
    static int[][] maze;
    static boolean[][] visited;
    static Queue<Coords> queue = new ArrayDeque<>();

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int getR() {
            return r;
        }

        public int getC() {
            return c;
        }

        public List<Coords> getNeighbors() {
            List<Coords> result = new ArrayList<>();
            int[] dr = new int[]{-1, 0, 1, 0};
            int[] dc = new int[]{0, -1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (0 <= nr && nr < N && 0 <= nc && nc < M)
                    result.add(new Coords(nr, nc));
            }

            return result;
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        maze = new int[N][M];
        visited = new boolean[N][M];
        for (int r = 0; r < N; r++) {
            String line = br.readLine();
            for (int c = 0; c < M; c++)
                maze[r][c] = line.charAt(c) - '0';
        }

        visited[0][0] = true;
        queue.offer(new Coords(0, 0));
        Outer: while (!queue.isEmpty()) {
            distance++;
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                if (curr.getR() == N - 1 && curr.getC() == M - 1)
                    break Outer;

                for (Coords ngbr : curr.getNeighbors())
                    if (maze[ngbr.getR()][ngbr.getC()] == 1 && !visited[ngbr.getR()][ngbr.getC()]) {
                        visited[ngbr.getR()][ngbr.getC()] = true;
                        queue.offer(ngbr);
                    }
            }
        }

        bw.write(String.valueOf(distance));

        bw.close();
        br.close();
    }
}
