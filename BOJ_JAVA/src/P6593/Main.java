package P6593;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int floor, row, column;

        public Node(int floor, int row, int column) {
            this.floor = floor;
            this.row = row;
            this.column = column;
        }

        public boolean equals(Node other) {
            return floor == other.floor && row == other.row && column == other.column;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final char START = 'S';
    static final char END = 'E';
    static final char BLOCKED = '#';

    static final int[] dl = {0, 0, -1, 0, 0, 1};
    static final int[] dr = {0, -1, 0, 0, 1, 0};
    static final int[] dc = {-1, 0, 0, 1, 0, 0};

    static int L, R, C, ret;
    static char[][][] status = new char[30][30][];
    static boolean[][][] visited = new boolean[30][30][30];
    static Queue<Node> queue = new LinkedList<>();
    static Node start, end;

    public static void main(String[] args) throws IOException {
        while (true) {
            tokens = br.readLine().split(" ");
            L = Integer.parseInt(tokens[0]);
            R = Integer.parseInt(tokens[1]);
            C = Integer.parseInt(tokens[2]);
            if (L == 0 && R == 0 && C == 0)
                break;

            for (int l = 0; l < L; ++l) {
                for (int r = 0; r < R; ++r) {
                    status[l][r] = br.readLine().toCharArray();
                    Arrays.fill(visited[l][r], false);
                    for (int c = 0; c < C; ++c) {
                        if (status[l][r][c] == START)
                            start = new Node(l, r, c);
                        else if (status[l][r][c] == END)
                            end = new Node(l, r, c);
                    }
                }
                br.readLine();
            }
            queue.clear();

            if ((ret = solve()) == -1)
                sb.append("Trapped!\n");
            else
                sb.append("Escaped in ").append(ret).append(" minute(s).\n");
        }
        System.out.print(sb);
    }

    public static int solve() {
        int distance = 0;

        visited[start.floor][start.row][start.column] = true;
        queue.offer(start);

        while (!queue.isEmpty()) {
            ++distance;
            int size = queue.size();
            while (size-- > 0) {
                Node node = queue.poll();
                for (int d = 0; d < 6; ++d) {
                    int l = node.floor + dl[d], r = node.row + dr[d], c = node.column + dc[d];
                    if (!isValidPoint(l, r, c) || visited[l][r][c] || status[l][r][c] == BLOCKED)
                        continue;

                    Node next = new Node(l, r, c);
                    if (next.equals(end))
                        return distance;

                    visited[l][r][c] = true;
                    queue.offer(next);
                }
            }
        }

        return -1;
    }

    public static boolean isValidPoint(int l, int r, int c) {
        return 0 <= l && l < L && 0 <= r && r < R && 0 <= c && c < C;
    }
}
