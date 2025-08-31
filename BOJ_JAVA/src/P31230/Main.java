package P31230;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int src, dest;
        long cost;

        public Edge(int src, int dest, long cost) {
            this.src = src;
            this.dest = dest;
            this.cost = cost;
        }

        public int getSrc() {
            return src;
        }

        public int getDest() {
            return dest;
        }

        public long getCost() {
            return cost;
        }

        public int compareTo(Edge other) {
            return Long.compare(cost, other.cost);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final long INF = Long.MAX_VALUE;

    static int N, M, A, B;
    static List<List<Edge>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= N; i++)
            graph.add(new ArrayList<>());
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int src = Integer.parseInt(st.nextToken());
            int dest = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph.get(src).add(new Edge(src, dest, cost));
            graph.get(dest).add(new Edge(dest, src, cost));
        }

        Map<Integer, List<Integer>> parents = dijkstra();
        List<Integer> result = findShortestPathNodes(parents);
        sb.append(result.size()).append('\n');
        for (int node : result)
            sb.append(node).append(' ');
        System.out.println(sb.toString());
    }

    public static Map<Integer, List<Integer>> dijkstra() {
        long[] distance = new long[N + 1];
        Map<Integer, List<Integer>> parents = new HashMap<>();
        Arrays.fill(distance, INF);

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        distance[A] = 0;
        pq.offer(new Edge(A, A, 0));
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int src = edge.getSrc(), mid = edge.getDest();
            long midCost = edge.getCost();
            if (distance[mid] < midCost)
                continue;

            for (Edge nextEdge : graph.get(mid)) {
                int dest = nextEdge.getDest();
                long destCost = nextEdge.getCost();
                if (midCost + destCost < distance[dest]) {
                    distance[dest] = midCost + destCost;
                    parents.put(dest, new ArrayList<>());
                    parents.get(dest).add(mid);
                    pq.offer(new Edge(src, dest, distance[dest]));
                } else if (midCost + destCost == distance[dest]) {
                    parents.put(dest, parents.getOrDefault(dest, new ArrayList<>()));
                    parents.get(dest).add(mid);
                }
            }
        }

        return parents;
    }

    public static List<Integer> findShortestPathNodes(Map<Integer, List<Integer>> parents) {
        List<Integer> list = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        Queue<Integer> queue = new ArrayDeque<>();
        set.add(B);
        queue.offer(B);
        list.add(B);
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            if (curr == A) {
                continue;
            }

            for (int parent : parents.get(curr))
                if (!set.contains(parent)) {
                    set.add(parent);
                    queue.add(parent);
                    list.add(parent);
                }
        }

        Collections.sort(list);
        return list;
    }
}
