package P2611;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static ArrayList<Neighbor>[] graph;
    private static ArrayList<Neighbor> candidates = new ArrayList<>();
    private static int[] distance;
    private static int[] inDegree;
    private static int[] parent;
    private static Queue<Integer> queue = new ArrayDeque<>();
    private static Deque<Integer> route = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        distance = new int[N + 1];
        inDegree = new int[N + 1];
        parent = new int[N + 1];

        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        while (M-- > 0) {
            String[] tokens = br.readLine().split(" ");
            int p = Integer.parseInt(tokens[0]);
            int q = Integer.parseInt(tokens[1]);
            int r = Integer.parseInt(tokens[2]);

            if (q == 1) {
                candidates.add(new Neighbor(p, r));
                continue;
            }

            graph[p].add(new Neighbor(q, r));
            inDegree[q]++;
        }

        queue.offer(1);
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            for (Neighbor neighbor : graph[curr]) {
                int node = neighbor.getNode();
                int cost = neighbor.getCost();

                if (distance[node] < distance[curr] + cost) {
                    distance[node] = distance[curr] + cost;
                    parent[node] = curr;
                }

                if (--inDegree[node] == 0) {
                    queue.offer(node);
                }
            }
        }

        for (Neighbor candidate : candidates) {
            int node = candidate.getNode();
            int cost = candidate.getCost();

            if (distance[1] < distance[node] + cost) {
                distance[1] = distance[node] + cost;
                parent[1] = node;
            }
        }

        bw.write(Integer.valueOf(distance[1]).toString() + "\n");
        route.push(1);
        for (int i = parent[1]; i != 1; i = parent[i]) {
            route.push(i);
        }
        route.push(1);
        while (!route.isEmpty()) {
            bw.write(route.pop().toString() + " ");
        }
        bw.flush();
        bw.close();
    }

    static class Neighbor {
        Integer node;
        Integer cost;

        public Neighbor(Integer node, Integer cost) {
            this.node = node;
            this.cost = cost;
        }

        public Integer getNode() {
            return node;
        }

        public Integer getCost() {
            return cost;
        }
    }
}
