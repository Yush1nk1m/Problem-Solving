package P1753;

import java.io.*;
import java.util.*;

public class Main {

    static class Info implements Comparable<Info> {
        int node, cost;

        public Info(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Info other) {
            return cost - other.cost;
        }

        public int getNode() {
            return node;
        }

        public int getCost() {
            return cost;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int V, E, K;
    static List<List<Info>> graph = new ArrayList<>();
    static final int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(br.readLine());
        for (int i = 0; i <= V; i++)
            graph.add(new ArrayList<>());
        while (E-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph.get(u).add(new Info(v, w));
        }
        int[] distances = dijkstra(K);
        for (int i = 1; i <= V; i++) {
            if (distances[i] == INF)
                bw.write("INF");
            else
                bw.write(String.valueOf(distances[i]));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }

    public static int[] dijkstra(int node) {
        PriorityQueue<Info> pq = new PriorityQueue<>();

        int[] distances = new int[V + 1];
        Arrays.fill(distances, INF);
        distances[node] = 0;
        pq.offer(new Info(node, 0));
        while (!pq.isEmpty()) {
            Info curr = pq.poll();

            for (Info ngbrInfo : graph.get(curr.getNode())) {
                int next = ngbrInfo.getNode(), cost = ngbrInfo.getCost();
                if (distances[curr.getNode()] + cost < distances[next]) {
                    distances[next] = distances[curr.getNode()] + cost;
                    pq.offer(new Info(next, distances[next]));
                }
            }
        }

        return distances;
    }
}
