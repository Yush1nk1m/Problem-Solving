package P1803;

import java.io.*;
import java.util.*;

class Main {

    static class Node {
        int type, index;

        public Node(int type, int index) {
            this.type = type;
            this.index = index;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int A = 0, B = 1;

    static int m, n;
    static List<Integer>[][] graph = new List[2][];
    static int[][] inDegree = new int[2][];
    static char[][] mark = new char[2][];
    static Queue<Node> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        m = Integer.parseInt(tokens[0]);
        n = Integer.parseInt(tokens[1]);
        graph[A] = new List[m + 1];
        for (int i = 1; i <= m; ++i)
            graph[A][i] = new ArrayList<>();
        graph[B] = new List[n + 1];
        for (int i = 1; i <= n; ++i)
            graph[B][i] = new ArrayList<>();
        inDegree[0] = new int[m + 1];
        inDegree[1] = new int[n + 1];
        mark[0] = new char[m + 1];
        mark[1] = new char[n + 1];
        tokens = br.readLine().split(" ");
        for (int a = 1; a <= m; ++a) {
            int b = Integer.parseInt(tokens[a - 1]);
            graph[A][a].add(b);
            ++inDegree[B][b];
        }
        tokens = br.readLine().split(" ");
        for (int b = 1; b <= n; ++b) {
            int a = Integer.parseInt(tokens[b - 1]);
            graph[B][b].add(a);
            ++inDegree[A][a];
        }

        for (int a = 1; a <= m; ++a)
            if (inDegree[A][a] == 0) {
                mark[A][a] = '1';
                queue.offer(new Node(A, a));
            }
        for (int b = 1; b <= n; ++b)
            if (inDegree[B][b] == 0) {
                mark[B][b] = '1';
                queue.offer(new Node(B, b));
            }
        BFS();
        for (int a = 1; a <= m; ++a)
            if (mark[A][a] == 0) {
                mark[A][a] = '0';
                queue.offer(new Node(A, a));
                BFS();
            }
        for (int b = 1; b <= n; ++b)
            if (mark[B][b] == 0) {
                mark[B][b] = '0';
                queue.offer(new Node(B, b));
                BFS();
            }

        for (int i = 1; i <= m; ++i)
            sb.append(mark[A][i]);
        sb.append('\n');
        for (int i = 1; i <= n; ++i)
            sb.append(mark[B][i]);
        System.out.println(sb);
    }

    public static void BFS() {
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            List<Integer> nodes = graph[curr.type][curr.index];
            if (mark[curr.type][curr.index] == '1') {
                for (int next : nodes)
                    if (mark[1 - curr.type][next] == 0) {
                        mark[1 - curr.type][next] = '0';
                        queue.offer(new Node(1 - curr.type, next));
                    }
            } else {
                for (int next : nodes)
                    if (mark[1 - curr.type][next] == 0 && --inDegree[1 - curr.type][next] == 0) {
                        mark[1 - curr.type][next] = '1';
                        queue.offer(new Node(1 - curr.type, next));
                    }
            }
        }
    }
}
