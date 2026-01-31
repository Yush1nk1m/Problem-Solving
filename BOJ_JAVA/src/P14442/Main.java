package P14442;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int b, r, c;

        public Node(int b, int r, int c) {
            this.b = b;
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};
    static final char WALL = '1';

    static int N, M, K;
    static char[][] table;
    static boolean[][][] visited;
    static Queue<Node> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    public static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);

        table = new char[N][];
        for (int r = 0; r < N; ++r)
            table[r] = br.readLine().toCharArray();
        visited = new boolean[K + 1][N][M];
    }

    public static int solve() {
        int distance = 0;

        visited[K][0][0] = true;
        queue.offer(new Node(K, 0, 0));

        while (!queue.isEmpty()) {
            ++distance;

            int size = queue.size();
            while (size-- > 0) {
                Node node = queue.poll();
                if (node.r == N - 1 && node.c == M - 1)
                    return distance;

                for (int d = 0; d < 4; ++d) {
                    int r = node.r + dr[d], c = node.c + dc[d];
                    if (!isValidPoint(r, c))
                        continue;
                    int b = table[r][c] == WALL ? node.b - 1 : node.b;
                    if (b < 0 || visited[b][r][c])
                        continue;
                    visited[b][r][c] = true;
                    queue.offer(new Node(b, r, c));
                }
            }
        }

        return -1;
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <=  c && c < M;
    }
}
