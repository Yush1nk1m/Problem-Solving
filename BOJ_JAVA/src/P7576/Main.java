package P7576;

import java.io.*;
import java.util.*;

public class Main {
    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int r() {
            return r;
        }

        public int c() {
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

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, M, nonMatured, day;
    static int[][] box;
    static boolean[][] visited;
    static Queue<Coords> queue = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        nonMatured = N * M;
        box = new int[N][M];
        visited = new boolean[N][M];

        for (int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < M; c++) {
                box[r][c] = Integer.parseInt(st.nextToken());
                if (box[r][c] == 1) {
                    nonMatured--;
                    visited[r][c] = true;
                    queue.offer(new Coords(r, c));
                } else if (box[r][c] == -1) {
                    nonMatured--;
                }
            }
        }

        while (nonMatured > 0 && !queue.isEmpty()) {
            day++;
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                for (Coords ngbr : curr.getNeighbors()) {
                    if (!visited[ngbr.r()][ngbr.c()] && box[ngbr.r()][ngbr.c()] != -1) {
                        nonMatured--;
                        visited[ngbr.r()][ngbr.c()] = true;
                        queue.offer(new Coords(ngbr.r(), ngbr.c()));
                    }
                }
            }
        }

        if (nonMatured > 0)
            bw.write("-1");
        else
            bw.write(String.valueOf(day));

        bw.close();
        br.close();
    }
}
