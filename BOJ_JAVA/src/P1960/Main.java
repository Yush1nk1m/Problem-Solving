package P1960;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int index, count;

        public Node(int index, int count) {
            this.index = index;
            this.count = count;
        }

        public int compareTo(Node other) {
            if (count == other.count)
                return Integer.compare(index, other.index);
            return Integer.compare(other.count, count);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int n;
    static int[] row, column;
    static int[][] matrix;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    static Queue<Node> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        row = new int[n];
        column = new int[n];
        matrix = new int[n][n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i)
            row[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i)
            column[i] = Integer.parseInt(st.nextToken());
    }

    private static void solve() {
        for (int c = 0; c < n; ++c)
            pq.offer(new Node(c, column[c]));
        for (int r = 0; r < n; ++r) {
            while (row[r]-- > 0)
                queue.offer(pq.poll());
            while (!queue.isEmpty()) {
                Node node = queue.poll();
                matrix[r][node.index] = 1;
                --column[node.index];
                --node.count;
                pq.offer(node);
            }
        }

        for (int i = 0; i < n; ++i)
            if (row[i] != -1 || column[i] != 0) {
                System.out.print("-1");
                return;
            }

        sb.append("1\n");
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c)
                sb.append(matrix[r][c]);
            sb.append('\n');
        }
        System.out.print(sb);
    }
}
