package P7868;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int d1, d2, d3;
        long value;

        public Node(int d1, int d2, int d3, long value) {
            this.d1 = d1;
            this.d2 = d2;
            this.d3 = d3;
            this.value = value;
        }

        public int compareTo(Node other) {
            return Long.compare(value, other.value);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int i;
    static long p1, p2, p3;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    static boolean[][][] visited = new boolean[50][50][50];

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        p1 = Long.parseLong(tokens[0]);
        p2 = Long.parseLong(tokens[1]);
        p3 = Long.parseLong(tokens[2]);
        i = Integer.parseInt(tokens[3]);
    }

    private static void solve() {
        Node curr = null;
        visited[1][0][0] = visited[0][1][0] = visited[0][0][1] = true;
        pq.offer(new Node(1, 0, 0, p1));
        pq.offer(new Node(0, 1, 0, p2));
        pq.offer(new Node(0, 0, 1, p3));
        while (i-- > 0) {
            curr = pq.poll();
            if (!visited[curr.d1 + 1][curr.d2][curr.d3]) {
                visited[curr.d1 + 1][curr.d2][curr.d3] = true;
                pq.offer(new Node(curr.d1 + 1, curr.d2, curr.d3, curr.value * p1));
            }
            if (!visited[curr.d1][curr.d2 + 1][curr.d3]) {
                visited[curr.d1][curr.d2 + 1][curr.d3] = true;
                pq.offer(new Node(curr.d1, curr.d2 + 1, curr.d3, curr.value * p2));
            }
            if (!visited[curr.d1][curr.d2][curr.d3 + 1]) {
                visited[curr.d1][curr.d2][curr.d3 + 1] = true;
                pq.offer(new Node(curr.d1, curr.d2, curr.d3 + 1, curr.value * p3));
            }
        }
        System.out.print(curr.value);
    }
}
