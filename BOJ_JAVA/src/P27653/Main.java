package P27653;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static long[] target;
    static List<List<Integer>> graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        target = new long[N + 1];
        graph = new ArrayList<>(N + 1);
        for (int i = 0; i < N + 1; ++i)
            graph.add(new ArrayList<>());
        visited = new boolean[N + 1];
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i)
            target[i] = Long.parseLong(tokens[i - 1]);
        for (int i = 0; i < N - 1; ++i) {
            tokens = br.readLine().split(" ");
            int u = Integer.parseInt(tokens[0]);
            int v = Integer.parseInt(tokens[1]);
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        System.out.println(DFS(0, 1));
    }

    public static long DFS(int parent, int curr) {
        visited[curr] = true;

        long ret = target[parent] < target[curr] ? target[curr] - target[parent] : 0;
        for (int next : graph.get(curr))
            if (!visited[next])
                ret += DFS(curr, next);

        return ret;
    }
}
