package P32755;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, u, v;
    static List<Integer>[] graph;
    static boolean[] visited;
    static Queue<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        graph = new List[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList<>();
        visited = new boolean[N + 1];

        for (int i = 0; i < N - 1; ++i) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            graph[u].add(v);
            graph[v].add(u);
        }
    }

    private static void solve() {
        int maxAdjacent = 0;
        for (int i = 1; i <= N; ++i)
            maxAdjacent = Math.max(maxAdjacent, graph[i].size());
        System.out.print(maxAdjacent == N - 1 ? N - 1 : N);
    }
}
