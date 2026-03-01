package P25498;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int i, index;
        char value;

        public Node(int i, int index, char value) {
            this.i = i;
            this.index = index;
            this.value = value;
        }

        public int compareTo(Node other) {
            if (index == other.index)
                return Character.compare(other.value, value);
            return Integer.compare(index, other.index);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, u, v;
    static char[] table, cache;
    static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        table = br.readLine().toCharArray();
        graph = new List[N];
        for (int i = 0; i < N; ++i)
            graph[i] = new ArrayList<>();
        for (int i = 0; i < N - 1; ++i) {
            tokens = br.readLine().split(" ");
            u = Integer.parseInt(tokens[0]) - 1;
            v = Integer.parseInt(tokens[1]) - 1;
            graph[u].add(v);
            graph[v].add(u);
        }
        cache = new char[N];
    }

    private static String solve() {
        int bound = 0;
        PriorityQueue<Node> queue = new PriorityQueue<>();
        boolean[] visited = new boolean[N];

        visited[0] = true;
        queue.offer(new Node(0, 0, table[0]));
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (cache[node.index] <= node.value) {
                bound = node.index + 1;
                cache[node.index] = node.value;
                for (int next : graph[node.i])
                    if (!visited[next]) {
                        visited[next] = true;
                        queue.offer(new Node(next, node.index + 1, table[next]));
                    }
            }
        }

        return new String(cache, 0, bound);
    }
}
