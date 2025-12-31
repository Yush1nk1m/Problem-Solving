package P14630;

import java.io.*;
import java.util.*;

public class Main {

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;

    static int N, source, destination;
    static String[] status;
    static int[][] graph;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        graph = new int[N + 1][N + 1];
        status = new String[N + 1];
        for (int i = 1; i <= N; ++i)
            status[i] = br.readLine();
        for (int r = 1; r <= N; ++r)
            for (int c = r + 1; c <= N; ++c)
                graph[r][c] = graph[c][r] = getCost(status[r], status[c]);
        tokens = br.readLine().split(" ");
        source = Integer.parseInt(tokens[0]);
        destination = Integer.parseInt(tokens[1]);
        System.out.print(solve(source, destination));
    }

    public static int getCost(String s1, String s2) {
        int cost = 0;
        for (int i = 0; i < s1.length(); ++i)
            cost += (int) Math.pow((int) (s1.charAt(i) - s2.charAt(i)), 2);
        return cost;
    }

    public static int solve(int source, int destination) {
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                if (p1.first == p2.first)
                    return Integer.compare(p1.second, p2.second);
                return Integer.compare(p1.first, p2.first);
            }
        });
        boolean[] expanded = new boolean[N + 1];
        int[] distance = new int[N + 1];
        Arrays.fill(distance, INF);

        pq.offer(new Pair(0, source));
        distance[source] = 0;
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int d = p.first;
            int curr = p.second;
            if (expanded[curr])
                continue;
            expanded[curr] = true;
            for (int next = 1; next <= N; ++next)
                if (graph[curr][next] + d < distance[next]) {
                    distance[next] = graph[curr][next] + d;
                    pq.offer(new Pair(distance[next], next));
                }
        }

        return distance[destination];
    }
}
