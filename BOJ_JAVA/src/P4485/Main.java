package P4485;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node>{
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
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int INF = 100_000_000;
    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static int N, i;
    static int[][] table = new int[125][125];

    public static void main(String[] args) throws IOException {
        while (++i != 0) {
            initialize();
            if (N == 0)
                break;
            sb.append("Problem ").append(i).append(": ").append(solve()).append('\n');
        }
        System.out.print(sb);
    }

    public static int solve() throws IOException {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[][] distance = new int[N][N];
        for (int[] row : distance)
            Arrays.fill(row, INF);

        distance[0][0] = table[0][0];
        pq.offer(new Node(0, 0, distance[0][0]));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            for (int d = 0; d < 4; ++d) {
                int r = node.r + dr[d], c = node.c + dc[d];
                if (!isValidPoint(r, c))
                    continue;

                int dist = node.distance + table[r][c];
                if (distance[r][c] <= dist)
                    continue;

                distance[r][c] = dist;
                pq.offer(new Node(r, c, distance[r][c]));
            }
        }

        return distance[N - 1][N - 1];
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }

    public static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; ++c)
                table[r][c] = Integer.parseInt(tokens[c]);
        }
    }
}
