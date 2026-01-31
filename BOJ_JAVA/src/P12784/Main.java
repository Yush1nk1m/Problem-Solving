package P12784;

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
    static StringBuilder sb = new StringBuilder();

    static final int INF = 100_000_000;

    static int T, N, M, u, v, d;
    static List<Pair>[] graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            initialize();
            sb.append(solve()).append('\n');
        }
        System.out.print(sb);
    }

    public static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        graph = new List[N +1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList<>();
        visited = new boolean[N + 1];
        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            u = Integer.parseInt(tokens[0]);
            v = Integer.parseInt(tokens[1]);
            d = Integer.parseInt(tokens[2]);
            graph[u].add(new Pair(v, d));
            graph[v].add(new Pair(u, d));
        }
    }

    public static int solve() {
        return N == 1 ? 0 : DFS(1);
    }

    public static int DFS(int root) {
        int count = 0;
        boolean isLeaf = true;
        visited[root] = true;

        for (Pair p : graph[root]) {
            int child = p.first;
            int d = p.second;
            if (visited[child])
                continue;
            isLeaf = false;
            count += Math.min(d, DFS(child));
        }

        return isLeaf ? INF : count;
    }
}
