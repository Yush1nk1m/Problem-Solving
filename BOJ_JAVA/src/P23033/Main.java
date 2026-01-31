package P23033;

import java.io.*;
import java.util.*;

public class Main {

    static class Line {
        int source, destination, time, interval;

        public Line(int source, int destination, int time, int interval) {
            this.source = source;
            this.destination = destination;
            this.time = time;
            this.interval = interval;
        }
    }

    static class Info implements Comparable<Info> {
        int node, time;

        public Info(int node, int time) {
            this.node = node;
            this.time = time;
        }

        public int compareTo(Info other) {
            return Integer.compare(time, other.time);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;

    static int N, M, A, B, T, W;
    static List<Line>[] graph;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        graph = new List[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList<>();
        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            A = Integer.parseInt(tokens[0]);
            B = Integer.parseInt(tokens[1]);
            T = Integer.parseInt(tokens[2]);
            W = Integer.parseInt(tokens[3]);
            graph[A].add(new Line(A, B, T, W));
        }
        System.out.print(solve());
    }

    public static int solve() {
        PriorityQueue<Info> pq = new PriorityQueue<>();
        boolean[] expanded = new boolean[N + 1];
        int[] distance = new int[N + 1];
        Arrays.fill(distance, INF);

        distance[1] = 0;
        pq.offer(new Info(1, 0));
        while (!pq.isEmpty()) {
            Info info = pq.poll();
            if (expanded[info.node])
                continue;
            expanded[info.node] = true;
            for (Line line : graph[info.node]) {
                int next = line.destination;
                int time = ((line.interval - (info.time % line.interval)) % line.interval) + line.time;
                if (distance[next] > distance[info.node] + time) {
                    distance[next] = distance[info.node] + time;
                    pq.offer(new Info(next, distance[next]));
                }
            }
        }

        return distance[N];
    }
}
