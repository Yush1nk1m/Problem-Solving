package P23354;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int r, c, cost;

        public Node(int r, int c, int cost) {
            this.r = r;
            this.c = c;
            this.cost = cost;
        }

        public int compareTo(Node other) {
            return Integer.compare(cost, other.cost);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;
    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static int N, size;
    static int[][] status, graph, cache;
    static Deque<Node> deque = new ArrayDeque<>();
    static List<Node> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        status = new int[N][N];
        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; ++c) {
                status[r][c] = Integer.parseInt(tokens[c]);
                if (status[r][c] == 0)
                    deque.addLast(new Node(r, c, 0));
                else if (status[r][c] == -1)
                    deque.addFirst(new Node(r, c, 0));
            }
        }
        size = deque.size();
        list = new ArrayList<>(deque);
        graph = new int[size][size];
        for (int i = 0; i < size; ++i)
            graph[i] = dijkstra(list.get(i));
        cache = new int[1 << size][size];
        for (int[] row : cache)
            Arrays.fill(row, INF);
        System.out.print(DFS(1, 0));
    }

    static int[] dijkstra(Node start) {
        int[] distance = new int[size];
        int[][] table = new int[N][N];
        PriorityQueue<Node> pq = new PriorityQueue<>();

        for (int[] row : table)
            Arrays.fill(row, INF);

        table[start.r][start.c] = 0;
        pq.offer(start);
        while (!pq.isEmpty()) {
            Node curr = pq.poll();
            if (curr.cost > table[curr.r][curr.c])
                continue;

            for (int d = 0; d < 4; ++d) {
                int nr = curr.r + dr[d], nc = curr.c + dc[d];
                if (!isValidPoint(nr, nc))
                    continue;

                int cost = curr.cost + Math.max(0, status[nr][nc]);
                if (cost < table[nr][nc]) {
                    table[nr][nc] = cost;
                    pq.offer(new Node(nr, nc, table[nr][nc]));
                }
            }
        }

        for (int i = 0; i < size; ++i)
            distance[i] = table[list.get(i).r][list.get(i).c];

        return distance;
    }

    static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }

    static int DFS(int mask, int curr) {
        if (mask == (1 << size) - 1)
            return graph[curr][0];
        else if (cache[mask][curr] != INF)
            return cache[mask][curr];

        for (int next = 0; next < size; ++next)
            if ((mask & (1 << next)) == 0)
                cache[mask][curr] = Math.min(cache[mask][curr], graph[curr][next] + DFS(mask | (1 << next), next));

        return cache[mask][curr];
    }
}
