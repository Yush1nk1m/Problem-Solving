package P1926;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int n, m;
    static int[][] paper;
    static boolean[][] visited;
    static int picNum = 0, maxArea = 0;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        paper = new int[n][m];
        visited = new boolean[n][m];

        for (int r = 0; r < n; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < m; c++)
                paper[r][c] = Integer.parseInt(st.nextToken());
        }

        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (!visited[r][c] && paper[r][c] == 1) {
                    picNum++;
                    maxArea = Math.max(maxArea, bfs(r, c));
                }

        bw.write(String.valueOf(picNum));
        bw.write('\n');
        bw.write(String.valueOf(maxArea));

        br.close();
        bw.close();
    }

    public static int bfs(int r, int c) {
        class Coords {
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
                    if (0 <= nr && nr < n && 0 <= nc && nc < m && paper[nr][nc] == 1)
                        result.add(new Coords(nr, nc));
                }

                return result;
            }
        }
        Queue<Coords> queue = new ArrayDeque<>();
        int size = 0;

        size++;
        visited[r][c] = true;
        queue.offer(new Coords(r, c));
        while (!queue.isEmpty()) {
            Coords curr = queue.poll();

            for (Coords next : curr.getNeighbors())
                if (!visited[next.getR()][next.getC()]) {
                    size++;
                    visited[next.getR()][next.getC()] = true;
                    queue.offer(next);
                }
        }

        return size;
    }
}
