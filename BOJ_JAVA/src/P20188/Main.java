package P20188;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, i, j;
    static List<Integer>[] graph;
    static long[] distance, size, sum;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        graph = new List[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList<>();
        distance = new long[N + 2];
        size = new long[N + 2];
        sum = new long[N + 2];
        visited = new boolean[N + 1];

        for (int t = 0; t < N - 1; t++) {
            st = new StringTokenizer(br.readLine());
            i = Integer.parseInt(st.nextToken());
            j = Integer.parseInt(st.nextToken());
            graph[i].add(j);
            graph[j].add(i);
        }
    }

    private static void solve() {
        long diversity = 0;

        DFS(1, 0L);

        for (int i = N; i >= 1; --i)
            sum[i] = distance[i] + sum[i + 1];

        for (int i = 1; i <= N - 1; ++i)
            diversity += sum[i] + (N - i - 1) * distance[i];
        for (int i = 2; i <= N; ++i)
            diversity -= (size[i] * (size[i] - 1)) >> 1;

        System.out.print(diversity);
    }

    private static long DFS(int root, long d) {
        visited[root] = true;
        distance[root] = d;
        size[root] = 1L;
        for (int next : graph[root])
            if (!visited[next])
                size[root] += DFS(next, d + 1);
        return size[root];
    }
}
