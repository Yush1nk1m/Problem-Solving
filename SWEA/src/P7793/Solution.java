package P7793;

import java.io.*;
import java.util.*;

public class Solution {

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int INF = 100_000_000;

    static final char DEVIL = '*';
    static final char ROCK = 'X';
    static final char SOURCE = 'S';
    static final char DESTINATION = 'D';

    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static int T, N, M;
    static char[][] table;
    static int[][] broken;
    static boolean[][] visited;
    static List<Coords> devils = new ArrayList<>();
    static Queue<Coords> queue = new LinkedList<>();
    static Coords source, destination;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        table = new char[N][];
        broken = new int[N][M];
        for (int[] row : broken)
            Arrays.fill(row, INF);
        visited = new boolean[N][M];

        devils.clear();
        for (int r = 0; r < N; ++r) {
            table[r] = br.readLine().toCharArray();
            for (int c = 0; c < M; ++c)
                switch (table[r][c]) {
                    case DEVIL:
                        devils.add(new Coords(r, c));
                        broken[r][c] = 0;
                        break;
                    case SOURCE:
                        source = new Coords(r, c);
                        visited[r][c] = true;
                        break;
                    case DESTINATION:
                        destination = new Coords(r, c);
                        visited[r][c] = true;
                        break;
                    case ROCK:
                        visited[r][c] = true;
                        broken[r][c] = 0;
                        break;
                }

            queue.clear();
        }
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');

        spreadDevils();
        int time = findMinimumDistance();

        sb.append(time == -1 ? "GAME OVER" : time).append('\n');
    }

    private static void spreadDevils() {
        for (Coords devil : devils) {
            visited[devil.r][devil.c] = true;
            queue.offer(devil);
        }

        while (!queue.isEmpty()) {
            Coords curr = queue.poll();

            for (int d = 0; d < 4; ++d) {
                int r = curr.r + dr[d], c = curr.c + dc[d];
                if (!isValidPoint(r, c) || visited[r][c])
                    continue;
                visited[r][c] = true;
                broken[r][c] = broken[curr.r][curr.c] + 1;
                queue.offer(new Coords(r, c));
            }
        }
    }

    private static int findMinimumDistance() {
        int time = 0;

        for (boolean[] row : visited)
            Arrays.fill(row, false);
        visited[source.r][source.c] = true;
        queue.offer(source);

        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                if (curr.r == destination.r && curr.c == destination.c)
                    return time;
                for (int d = 0; d < 4; ++d) {
                    int r = curr.r + dr[d], c = curr.c + dc[d];
                    if (!isValidPoint(r, c) || visited[r][c] || time + 1 >= broken[r][c])
                        continue;
                    visited[r][c] = true;
                    queue.offer(new Coords(r, c));
                }
            }
            ++time;
        }
        return -1;
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M;
    }
}
