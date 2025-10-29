package P19542;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, S, D, x, y;
    static int[] depth;
    static boolean[] visited;
    static List<List<Integer>> graph;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        S = Integer.parseInt(tokens[1]);
        D = Integer.parseInt(tokens[2]);

        depth = new int[N + 1];
        visited = new boolean[N + 1];
        graph = new ArrayList<>(N + 1);
        for (int i = 0; i < N + 1; ++i)
            graph.add(new ArrayList<>());

        for (int i = 0; i < N - 1; ++i) {
            tokens = br.readLine().split(" ");
            x = Integer.parseInt(tokens[0]);
            y = Integer.parseInt(tokens[1]);
            graph.get(x).add(y);
            graph.get(y).add(x);
        }

        initializeDepth(S);

        Arrays.fill(visited, false);
        System.out.println(DFS(S));
    }

    public static int initializeDepth(int root) {
        visited[root] = true;

        for (int next : graph.get(root))
            if (!visited[next])
                depth[root] = Math.max(depth[root], initializeDepth(next));

        return ++depth[root];
    }

    public static int DFS(int root) {
        visited[root] = true;

        int ret = 0;
        for (int next : graph.get(root))
            if (!visited[next] && depth[next] > D)
                ret += 2 + DFS(next);

        return ret;
    }
}
