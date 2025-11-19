package P30024;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int r, c, value;

        public Node(int r, int c, int value) {
            this.r = r;
            this.c = c;
            this.value = value;
        }

        public int compareTo(Node other) {
            return -Integer.compare(value, other.value);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static int N, M, K;
    static int[][] table;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        table = new int[N + 2][M + 2];
        visited = new boolean[N + 2][M + 2];
        for (int r = 0; r < N + 2; ++r)
            visited[r][0] = visited[r][M + 1] = true;
        for (int c = 0; c < M + 2; ++c)
            visited[0][c] = visited[N + 1][c] = true;

        for (int r = 1; r <= N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 1; c <= M; ++c)
                table[r][c] = Integer.parseInt(tokens[c - 1]);
        }

        K = Integer.parseInt(br.readLine());

        BFS();
        System.out.println(sb);
    }

    public static void BFS() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (int r = 1; r <= N; ++r) {
            pq.offer(new Node(r, 1, table[r][1]));
            if (M != 1)
                pq.offer(new Node(r, M, table[r][M]));
            visited[r][1] = visited[r][M] = true;
        }
        for (int c = 2; c <M; ++c) {
            pq.offer(new Node(1, c, table[1][c]));
            if (N != 1)
                pq.offer(new Node(N, c, table[N][c]));
            visited[1][c] = visited[N][c] = true;
        }

        while (K > 0 && !pq.isEmpty()) {
            --K;
            Node curr = pq.poll();
            int r = curr.r, c = curr.c;
            sb.append(r).append(' ').append(c).append('\n');
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (visited[nr][nc])
                    continue;
                visited[nr][nc] = true;
                pq.offer(new Node(nr, nc, table[nr][nc]));
            }
        }
    }
}
