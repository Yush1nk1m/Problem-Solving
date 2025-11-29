package P20136;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int id, next;

        public Node(int id, int next) {
            this.id = id;
            this.next = next;
        }

        public int compareTo(Node other) {
            return Integer.compare(other.next, this.next);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;

    static int N, K;
    static int[] sequence;
    static boolean[] visited;
    static Queue<Integer>[] indices;
    static PriorityQueue<Node> outlet = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);
        tokens = br.readLine().split(" ");
        sequence = new int[K];
        visited = new boolean[K + 1];
        indices = new Queue[K + 1];
        for (int i = 0; i < K; ++i) {
            sequence[i] = Integer.parseInt(tokens[i]);
            if (indices[sequence[i]] == null)
                indices[sequence[i]] = new LinkedList<>();
            indices[sequence[i]].offer(i);
        }
        for (int i = 1; i <= K; ++i)
            if (indices[i] != null) {
                indices[i].poll();
                indices[i].offer(INF);
            }
        System.out.println(solve());
    }

    public static int solve() {
        if (N >= K)
            return 0;

        int count = 0, visitedCount = 0;

        for (int id : sequence) {
            int next = indices[id].poll();
            if (visited[id]) {
                outlet.offer(new Node(id, next));
                continue;
            }

            if (visitedCount == N) {
                ++count;
                while (visitedCount == N) {
                    Node node = outlet.poll();
                    if (visited[node.id]) {
                        visited[node.id] = false;
                        --visitedCount;
                    }
                }
            }

            visited[id] = true;
            ++visitedCount;
            outlet.offer(new Node(id, next));
        }

        return count;
    }
}
