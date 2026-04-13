package P33888;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, seq;
    static List<Integer>[] graph;
    static int[] degree, id = new int[6];
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        degree = new int[N + 1];
        visited = new boolean[N + 1];
        graph = new List[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList<>();

        for (int i = 0; i < N + 3; ++i) {
            tokens = br.readLine().split(" ");
            int u = Integer.parseInt(tokens[0]);
            int v = Integer.parseInt(tokens[1]);
            ++degree[u];
            ++degree[v];
            graph[u].add(v);
            graph[v].add(u);
        }
    }

    private static void solve() {
        for (int i = 1; i <= N; ++i)
            if (degree[i] == 1) {
                visited[i] = true;
                id[seq++] = i;

                int bottom = DFS(id[0]);
                id[seq++] = bottom;
                break;
            }

        for (int next : graph[id[1]])
            if (!visited[next]) {
                int core = DFS(next);
                id[seq++] = core;
            }

        for (int i = 1; i <= N; ++i)
            if (!visited[i] && degree[i] == 3) {
                id[seq++] = i;
                break;
            }

        if (degree[id[2]] == 4) { int t = id[2]; id[2] = id[3]; id[3] = t; }
        else if (degree[id[4]] == 4) { int t = id[4]; id[4] = id[3]; id[3] = t; }
        if (id[2] < id[4]) { int t = id[2]; id[2] = id[4]; id[4] = t; }

        for (int i = 5; i >= 0; --i)
            sb.append(id[i]).append(' ');

        System.out.print(sb);
    }

    private static int DFS(int root) {
        visited[root] = true;

        if (degree[root] >= 3)
            return root;
        return !visited[graph[root].get(0)]
                ? DFS(graph[root].get(0))
                : DFS(graph[root].get(1));
    }
}
