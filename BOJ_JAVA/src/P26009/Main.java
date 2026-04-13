package P26009;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int r, c, ttl;

        public Node(int r, int c, int ttl) {
            this.r = r;
            this.c = c;
            this.ttl = ttl;
        }

        public int compareTo(Node other) {
            return Integer.compare(other.ttl, ttl);
        }
    }

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static int N, M, K, R, C, D;
    static int[][] maxTTL;
    static boolean[][] visited;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    static Queue<Coords> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new boolean[N + 1][M + 1];
        maxTTL = new int[N + 1][M + 1];
        for (int[] row : maxTTL)
            Arrays.fill(row, -1);

        K = Integer.parseInt(br.readLine());
        while (K-- > 0) {
            st = new StringTokenizer(br.readLine());
            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            visited[R][C] = true;
            if (D > maxTTL[R][C]) {
                maxTTL[R][C] = D;
                pq.offer(new Node(R, C, D));
            }
        }
    }

    private static void solve() {
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            if (node.ttl <= 0)
                continue;

            for (int d = 0; d < 4; ++d) {
                int r = node.r + dr[d], c = node.c + dc[d], ttl = node.ttl - 1;
                if (!isValidPoint(r, c))
                    continue;

                visited[r][c] = true;
                if (maxTTL[r][c] < ttl) {
                    maxTTL[r][c] = ttl;
                    pq.offer(new Node(r, c, ttl));
                }
            }
        }

        int distance = 0;
        queue.offer(new Coords(1, 1));
        visited[1][1] = true;

        while (!queue.isEmpty() && !visited[N][M]) {
            int size = queue.size();
            ++distance;

            while (size-- > 0) {
                Coords coords = queue.poll();
                for (int d = 0; d < 4; ++d) {
                    int r = coords.r + dr[d], c = coords.c + dc[d];
                    if (!isValidPoint(r, c) || visited[r][c])
                        continue;

                    visited[r][c] = true;
                    queue.offer(new Coords(r, c));
                }
            }
        }

        if (visited[N][M])
            System.out.print("YES\n" + distance);
        else
            System.out.print("NO");
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 < r && r <= N && 0 < c && c <= M;
    }
}
