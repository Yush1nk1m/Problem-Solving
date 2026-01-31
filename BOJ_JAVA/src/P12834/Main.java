package P12834;

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

    static int INF = 100_000_000;

    static int N, V, E, A, B, a, b, l, total;
    static int[] H;
    static List<Pair>[] graph;
    static int[] distance;
    static PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
        @Override
        public int compare(Pair p1, Pair p2) {
            return Integer.compare(p1.second, p2.second);
        }
    });

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        V = Integer.parseInt(tokens[1]);
        E = Integer.parseInt(tokens[2]);

        tokens = br.readLine().split(" ");
        A = Integer.parseInt(tokens[0]);
        B = Integer.parseInt(tokens[1]);

        tokens = br.readLine().split(" ");
        H = new int[N];
        for (int i = 0; i < N; ++i)
            H[i] = Integer.parseInt(tokens[i]);

        graph = new List[V + 1];
        for (int i = 1; i <= V; ++i)
            graph[i] = new ArrayList<>();
        while (E-- > 0) {
            tokens = br.readLine().split(" ");
            a = Integer.parseInt(tokens[0]);
            b = Integer.parseInt(tokens[1]);
            l = Integer.parseInt(tokens[2]);
            graph[a].add(new Pair(b, l));
            graph[b].add(new Pair(a, l));
        }

        distance = new int[V + 1];
        for (int home : H)
            total += dijkstra(home);

        System.out.print(total);
    }

    public static int dijkstra(int begin) {
        Arrays.fill(distance, INF);
        pq.clear();

        distance[begin] = 0;
        pq.offer(new Pair(begin, distance[begin]));
        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            for (Pair next : graph[curr.first])
                if (distance[next.first] > curr.second + next.second) {
                    distance[next.first] = curr.second + next.second;
                    pq.offer(new Pair(next.first, distance[next.first]));
                }
        }

        distance[A] = distance[A] == INF ? -1 : distance[A];
        distance[B] = distance[B] == INF ? -1 : distance[B];

        return distance[A] + distance[B];
    }
}
