package P31795;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final long MOD = 1_000_000_007L;

    static int N, M, Q, u, v, p, q;
    static long total;
    static long[] w, cache, rcache;
    static Set<Integer>[] graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        Q = Integer.parseInt(tokens[2]);

        graph = new Set[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new HashSet<>();
        w = new long[N + 1];
        cache = new long[N + 1];
        rcache = new long[N + 1];
        visited = new boolean[N + 1];

        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i)
            w[i] = Long.parseLong(tokens[i - 1]);

        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            u = Integer.parseInt(tokens[0]);
            v = Integer.parseInt(tokens[1]);
            graph[u].add(v);
            graph[v].add(u);
        }

        for (int i = 1; i <= N; ++i) {
            if (!visited[i])
                DFS(i);
            total += cache[i];
            total %= MOD;
        }
        Arrays.fill(visited, false);
        for (int i = 1; i <= N; ++i)
            if (!visited[i])
                reverseDFS(i);

        while (Q-- > 0) {
            tokens = br.readLine().split(" ");
            p = Integer.parseInt(tokens[0]);
            q = Integer.parseInt(tokens[1]);
            sb.append(solve(p, q)).append('\n');
        }

        System.out.print(sb);
    }

    public static long solve(int p, int q) {
        if (w[p] == w[q])
            return total;
        else if (w[p] > w[q]) {
            int t = p;
            p = q;
            q = t;
        }

        if (graph[p].contains(q))
            return ((total - (rcache[p] * cache[q]) % MOD) + MOD) % MOD;
        else
            return (total + (rcache[p] * cache[q]) % MOD) % MOD;
    }

    public static long DFS(int root) {
        if (cache[root] != 0)
            return cache[root];

        visited[root] = true;
        cache[root] = 1;
        for (int next : graph[root])
            if (w[root] < w[next]) {
                cache[root] += DFS(next);
                cache[root] %= MOD;
            }

        return cache[root];
    }

    public static long reverseDFS(int root) {
        if (rcache[root] != 0)
            return rcache[root];

        visited[root] = true;
        rcache[root] = 1;
        for (int next : graph[root])
            if (w[root] > w[next]) {
                rcache[root] += reverseDFS(next);
                rcache[root] %= MOD;
            }

        return rcache[root];
    }
}
