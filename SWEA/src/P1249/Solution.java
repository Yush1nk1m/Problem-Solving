package P1249;

import java.io.*;
import java.util.*;

public class Solution {

    static class Node implements Comparable<Node> {
        int r, c, distance;

        public Node(int r, int c, int distance) {
            this.r = r;
            this.c = c;
            this.distance = distance;
        }

        public int compareTo(Node other) {
            return Integer.compare(distance, other.distance);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static int T, N;
    static int[][] table, distance;
    static PriorityQueue<Node> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        table = new int[N][N];
        distance = new int[N][N];
        for (int[] row : distance)
            Arrays.fill(row, Integer.MAX_VALUE);
        for (int r = 0; r < N; ++r) {
            String line = br.readLine();
            for (int c = 0; c < N; ++c)
                table[r][c] = line.charAt(c) - '0';
        }
        pq.clear();
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');

        pq.offer(new Node(0, 0, 0));
        while (!pq.isEmpty() && distance[N - 1][N - 1] == Integer.MAX_VALUE) {
            Node node = pq.poll();
            distance[node.r][node.c] = node.distance;

            for (int d = 0; d < 4; ++d) {
                int r = node.r + dr[d], c = node.c + dc[d];
                if (!isValidPoint(r, c) || distance[r][c] <= distance[node.r][node.c] + table[r][c])
                    continue;
                pq.offer(new Node(r, c, distance[node.r][node.c] + table[r][c]));
            }
        }

        sb.append(distance[N - 1][N - 1]).append('\n');
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
}
