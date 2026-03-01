package P33712;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords {

        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static class Status {

        static int[][] dr = {
                {-2, 0, 1, 0},
                {-1, 0, 2, 0},
                {-1, 0, 1, 0}
        };
        static int[][] dc = {
                {0, 1, 0, -2},
                {0, 1, 0, -1},
                {0, 2, 0, -1}
        };
        static int[][] next = {
                {1, 2, 1, 2},
                {0, 1, 0, 1},
                {2, 0, 2, 0}
        };

        int r, c, type;

        public Status(int r, int c, int type) {
            this.r = r;
            this.c = c;
            this.type = type;
        }

        public Status move(int direction) {
            int nr = r + dr[type][direction], nc = c + dc[type][direction], ntype = next[type][direction];
            Status status = new Status(nr, nc, ntype);
            if (!status.isValidStatus())
                return null;
            return status;
        }

        private boolean isValidStatus() {
            if (!isValidPoint(r, c) || table[r][c] == OUTSIDE)
                return false;

            switch (type) {
                case 0:
                    return true;
                case 1:
                    return isValidPoint(r + 1, c) && table[r + 1][c] != OUTSIDE;
                case 2:
                    return isValidPoint(r, c + 1) && table[r][c + 1] != OUTSIDE;
                default:
                    return false;
            }
        }

        private boolean isValidPoint(int r, int c) {
            return 0 <= r && r < M && 0 <= c && c < N;
        }
    }

    static class Node {

        Status status;
        int count;

        public Node(Status status, int count) {
            this.status = status;
            this.count = count;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int OUTSIDE = 0;
    static int TARGET = 2;

    static int N, M, K;
    static int[][] table;
    static boolean[][] placeable;
    static boolean[][][][] visited;
    static Queue<Node> queue = new LinkedList<>();
    static Coords target;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        M = Integer.parseInt(tokens[0]);
        N = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);

        table = new int[M][N];
        for (int r = 0; r < M; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; ++c) {
                table[r][c] = Integer.parseInt(tokens[c]);
                if (table[r][c] == TARGET)
                    target = new Coords(r, c);
            }
        }
        placeable = new boolean[M][N];
        visited = new boolean[M][N][3][K + 1];
    }

    private static int solve() {
        int count = 0;
        BFS();
        for (int r = 0; r < M; ++r)
            for (int c = 0; c < N; ++c)
                count += placeable[r][c] ? 1 : 0;
        return count;
    }

    private static void BFS() {
        visited[target.r][target.c][0][K] = true;
        queue.offer(new Node(new Status(target.r, target.c, 0), K));

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            Status status = node.status;
            int count = node.count;

            if (count == 0) {
                if (status.type == 0 && (status.r != target.r || status.c != target.c))
                    placeable[status.r][status.c] = true;
                continue;
            }

            for (int d = 0; d < 4; ++d) {
                Status next = status.move(d);
                if (next == null || visited[next.r][next.c][next.type][count - 1])
                    continue;
                visited[next.r][next.c][next.type][count - 1] = true;
                queue.offer(new Node(next, count - 1));
            }
        }
    }
}
