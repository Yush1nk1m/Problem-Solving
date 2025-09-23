package P5719;

import java.io.*;
import java.util.*;

class Main {

    static class Pair implements Comparable<Pair> {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair other) {
            if (first == other.first)
                return second - other.second;
            return first - other.first;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int INF = 100_000_000;

    static int N, M, S, D, U, V, P;
    static int[][] graph;
    static List<List<Integer>> parent;

    public static void main(String[] args) throws IOException {
        int ret;
        while ((ret = solve()) != -INF)
            sb.append(ret).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        if (!initialize())
            return -INF;

        dijkstra(true);
        int ret = dijkstra(false);
        return ret == INF ? -1 : ret;
    }

    public static boolean initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        if (N == 0 && M == 0)
            return false;
        graph = new int[N][N];
        for (int[] row : graph)
            Arrays.fill(row, INF);

        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            U = Integer.parseInt(st.nextToken());
            V = Integer.parseInt(st.nextToken());
            P = Integer.parseInt(st.nextToken());
            graph[U][V] = P;
        }

        return true;
    }

    public static int dijkstra(boolean remove) {
        int[] distance = new int[N];
        Arrays.fill(distance, INF);
        boolean[] visited = new boolean[N];
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        parent = new ArrayList<>();
        for (int i = 0; i < N; i++)
            parent.add(new ArrayList<>());

        distance[S] = 0;
        pq.offer(new Pair(0, S));
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int curr = p.second;
            if (visited[curr])
                continue;
            visited[curr] = true;

            for (int next = 0; next < N; next++) {
                if (graph[curr][next] == INF)
                    continue;
                if (distance[curr] + graph[curr][next] < distance[next]) {
                    distance[next] = distance[curr] + graph[curr][next];
                    pq.offer(new Pair(distance[next], next));
                    parent.get(next).clear();
                    parent.get(next).add(curr);
                } else if (distance[curr] + graph[curr][next] == distance[next]) {
                    parent.get(next).add(curr);
                }
            }
        }

        if (remove)
            removePathEdges();

        return distance[D];
    }

    public static void removePathEdges() {
        boolean[] visited = new boolean[N];
        Queue<Integer> queue = new LinkedList<>();

        visited[D] = true;
        queue.offer(D);
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            for (int prev : parent.get(curr)) {
                graph[prev][curr] = INF;
                if (!visited[prev]) {
                    visited[prev] = true;
                    queue.offer(prev);
                }
            }
        }
    }
}
