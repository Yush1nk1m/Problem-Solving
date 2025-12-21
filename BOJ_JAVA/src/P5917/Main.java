package P5917;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge>{
        int source, destination, weight;

        public Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }

        public int compareTo(Edge other) {
            return Integer.compare(weight, other.weight);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;

    static int N, M, baseline, result;
    static int[][] graph;
    static List<Edge> edgeList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        graph = new int[N + 1][N + 1];
        for (int[] row : graph)
            Arrays.fill(row, INF);
        for (int i = 0; i <= N; ++i)
            graph[i][i] = 0;
        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            int source = Integer.parseInt(tokens[0]);
            int destination = Integer.parseInt(tokens[1]);
            int weight = Integer.parseInt(tokens[2]);
            edgeList.add(new Edge(source, destination, weight));
            graph[source][destination] = graph[destination][source] = weight;
        }

        baseline = dijkstra();
        for (Edge edge : edgeList) {
            graph[edge.source][edge.destination] = graph[edge.destination][edge.source] = edge.weight << 1;
            result = Math.max(result, dijkstra() - baseline);
            graph[edge.source][edge.destination] = graph[edge.destination][edge.source] = edge.weight;
        }

        System.out.println(result);
    }

    public static int dijkstra() {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] expanded = new boolean[N + 1];
        int[] distance = new int[N + 1];

        Arrays.fill(distance, INF);
        distance[1] = 0;
        pq.offer(new Edge(1, 1, 0));
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            if (expanded[edge.destination])
                continue;
            expanded[edge.destination] = true;

            for (int next = 1; next <= N; ++next)
                if (distance[edge.destination] + graph[edge.destination][next] < distance[next]) {
                    distance[next] = distance[edge.destination] + graph[edge.destination][next];
                    pq.offer(new Edge(edge.destination, next, distance[next]));
                }
        }

        return distance[N];
    }
}
