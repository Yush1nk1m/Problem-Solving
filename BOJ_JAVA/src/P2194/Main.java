package P2194;

import java.io.*;
import java.util.*;

public class Main {

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
            List<Coords> list = new ArrayList<>();
            int[] dr = new int[]{-1, 0, 1, 0};
            int[] dc = new int[]{0, -1, 0, 1};
            for (int i = 0; i < 4; i++)
                list.add(new Coords(r + dr[i], c + dc[i]));
            return list;
        }

        public static boolean isValidPoint(Coords coords) {
            for (int r = coords.getR(); r < coords.getR() + A; r++)
                for (int c = coords.getC(); c < coords.getC() + B; c++)
                    if (map[r][c] == OBSTACLE)
                        return false;
            return true;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, M, A, B, K, sr, sc, er, ec;
    static int[][] map;
    static boolean[][] visited;
    static final int EMPTY = 0;
    static final int OBSTACLE = 1;
    static Queue<Coords> queue = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        map = new int[N + 2][M + 2];
        visited = new boolean[N + 2][M + 2];
        while (K-- > 0) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            map[r][c] = OBSTACLE;
        }
        for (int r = 0; r <= N + 1; r++)
            map[r][0] = map[r][M + 1] = OBSTACLE;
        for (int c = 0; c <= M + 1; c++)
            map[0][c] = map[N + 1][c] = OBSTACLE;
        st = new StringTokenizer(br.readLine());
        sr = Integer.parseInt(st.nextToken());
        sc = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        er = Integer.parseInt(st.nextToken());
        ec = Integer.parseInt(st.nextToken());

        int distance = 0;
        boolean reached = false;
        visited[sr][sc] = true;
        queue.offer(new Coords(sr, sc));
        Outer: while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                if (curr.getR() == er && curr.getC() == ec) {
                    reached = true;
                    break Outer;
                }

                for (Coords next : curr.getNeighbors()) {
                    int r = next.getR(), c = next.getC();
                    if (Coords.isValidPoint(next) && !visited[r][c]) {
                        visited[r][c] = true;
                        queue.offer(next);
                    }
                }
            }
            distance++;
        }

        if (reached)
            bw.write(String.valueOf(distance));
        else
            bw.write("-1");
        bw.flush();

        br.close();
        bw.close();
    }
}
