package P7673;

import java.io.*;
import java.util.*;

public class Solution {

    static class Node implements Comparable<Node> {
        int r, c;
        Info info;

        public Node(int r, int c, Info info) {
            this.r = r;
            this.c = c;
            this.info = info;
        }

        public int compareTo(Node other) {
            return Integer.compare(Math.min(info.m2, info.m5), Math.min(other.info.m2, other.info.m5));
        }
    }

    static class Info {
        int m2, m5;

        public Info(int m2, int m5) {
            this.m2 = m2;
            this.m5 = m5;
        }

        public static Info build(int number) {
            if (number == 0) return null;
            int m2 = 0, m5 = 0;
            while (number % 2 == 0 && number > 0) {
                number >>= 1;
                ++m2;
            }
            while (number % 5 == 0 && number > 0) {
                number /= 5;
                ++m5;
            }
            return new Info(m2, m5);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final Info INF = new Info(100_000_000, 100_000_000);

    static final int[] dr = {1, 0};
    static final int[] dc = {0, 1};

    static int T, N;
    static Info[][] table, cache;
    static boolean[][] expanded;

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
        table = new Info[N][N];
        cache = new Info[N][N];
        expanded = new boolean[N][N];
        for (Info[] row : cache)
            Arrays.fill(row, INF);

        for (int r = 0; r < N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < N; ++c)
                table[r][c] = Info.build(Integer.parseInt(st.nextToken()));
        }
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(0, 0, table[0][0]));

        while (!pq.isEmpty()) {
            Node curr = pq.poll();
            if (curr.r == N - 1 && curr.c == N - 1) {
                sb.append(Math.min(curr.info.m2, curr.info.m5)).append('\n');
                return;
            } else if (expanded[curr.r][curr.c]) continue;

            expanded[curr.r][curr.c] = true;
            cache[curr.r][curr.c] = curr.info;

            for (int d = 0; d < 2; ++d) {
                int r = curr.r + dr[d], c = curr.c + dc[d];
                if (!isValidPoint(r, c) || table[r][c] == null ||
                        Math.min(curr.info.m2 + table[r][c].m2, curr.info.m5 + table[r][c].m5) >= Math.min(cache[r][c].m2, cache[r][c].m5))
                    continue;
                pq.offer(new Node(r, c, new Info(curr.info.m2 + table[r][c].m2, curr.info.m5 + table[r][c].m5)));
            }
        }
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
}
