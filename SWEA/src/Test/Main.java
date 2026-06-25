package Test;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords implements Comparable<Coords> {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int compareTo(Coords other) {
            if (r == other.r)
                return Integer.compare(c, other.c);
            return Integer.compare(r, other.r);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static int N, K;
    static Coords point;
    static int[][] table;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        table = new int[N][N];
        for (int r = 0; r < N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < N; ++c)
                table[r][c] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        point = new Coords(
                Integer.parseInt(st.nextToken()) - 1,
                Integer.parseInt(st.nextToken()) - 1);
    }

    private static void solve() {
        while (K-- > 0)
            point = BFS(point);
        System.out.println((point.r + 1) + " " + (point.c + 1));
    }

    private static Coords BFS(Coords start) {
        int maxValue = 0;
        Coords maxCoords = null;
        boolean[][] visited = new boolean[N][N];
        Queue<Coords> queue = new LinkedList<>();

        visited[start.r][start.c] = true;
        queue.offer(start);
        while (!queue.isEmpty()) {
            Coords curr = queue.poll();

            for (int d = 0; d < 4; ++d) {
                int r = curr.r + dr[d], c = curr.c + dc[d];
                if (!isValidPoint(r, c) || visited[r][c] || table[r][c] >= table[start.r][start.c])
                    continue;
                visited[r][c] = true;
                Coords next = new Coords(r, c);
                queue.offer(next);
                if (table[r][c] >= maxValue && (maxCoords == null || next.compareTo(maxCoords) < 0)) {
                    maxValue = table[r][c];
                    maxCoords = next;
                }
            }
        }

        return maxCoords == null ? start : maxCoords;
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
}