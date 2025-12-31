package P32936;

import java.io.*;
import java.util.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        long first;
        int second;

        public Pair(long first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair other) {
            if (first == other.first)
                return Integer.compare(second, other.second);
            return Long.compare(first, other.first);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final long INF = 1_000_000_001L;

    static int N, M, a, b;
    static long c;
    static long[] distanceFirst, distanceMiddle;
    static Set<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        a = Integer.parseInt(tokens[2]);
        b = Integer.parseInt(tokens[3]);
        c = Long.parseLong(tokens[4]);

        graph = new Set[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new HashSet<>();

        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            int src = Integer.parseInt(tokens[0]);
            int dest = Integer.parseInt(tokens[1]);
            graph[src].add(dest);
        }

        distanceFirst = dijkstra(1);
        distanceMiddle = dijkstra(b);
        if (distanceMiddle[a] < c && distanceMiddle[N] != INF && distanceFirst[a] != INF)
            System.out.print("-inf");
        else if (distanceFirst[N] != INF || (distanceFirst[a] != INF && distanceMiddle[N] != INF))
            System.out.print(Math.min(
                    distanceFirst[N],
                    distanceFirst[a] - c + distanceMiddle[N]
            ));
        else
            System.out.print("x");
    }

    public static long[] dijkstra(int start) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        boolean[] expanded = new boolean[N + 1];
        long[] distance = new long[N + 1];
        Arrays.fill(distance, INF);

        distance[start] = 0L;
        pq.offer(new Pair(distance[start], start));
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            long d = p.first;
            int curr = p.second;

            if (expanded[curr])
                continue;
            expanded[curr] = true;

            for (int next : graph[curr])
                if (distance[next] > d + 1L) {
                    distance[next] = d + 1L;
                    pq.offer(new Pair(distance[next], next));
                }
        }

        return distance;
    }
}
