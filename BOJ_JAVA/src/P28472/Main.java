package P28472;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, R, L, Q;
    static int[] value;
    static boolean[] visited;
    static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        R = Integer.parseInt(tokens[1]);
        value = new int[N + 1];
        visited = new boolean[N + 1];
        graph = new List[N + 1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList<>();

        for (int i = 0; i < N - 1; ++i) {
            tokens = br.readLine().split(" ");
            int u = Integer.parseInt(tokens[0]);
            int v = Integer.parseInt(tokens[1]);
            graph[u].add(v);
            graph[v].add(u);
        }
        fillValue(R, 0);
        Arrays.fill(visited, false);

        L = Integer.parseInt(br.readLine());
        while (L-- > 0) {
            tokens = br.readLine().split(" ");
            int n = Integer.parseInt(tokens[0]);
            int v = Integer.parseInt(tokens[1]);
            value[n] = v;
        }
        initTree(R, 0);

        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0)
            sb.append(value[Integer.parseInt(br.readLine())]).append('\n');
        System.out.println(sb);
    }

    public static void fillValue(int root, int depth) {
        visited[root] = true;
        value[root] = depth % 2 == 0 ? Integer.MIN_VALUE : Integer.MAX_VALUE;

        for (int child : graph[root])
            if (!visited[child])
                fillValue(child, depth + 1);
    }

    public static int initTree(int root, int depth) {
        visited[root] = true;

        for (int child : graph[root])
            if (!visited[child]) {
                if (depth % 2 == 0)
                    value[root] = Math.max(value[root], initTree(child, depth + 1));
                else
                    value[root] = Math.min(value[root], initTree(child, depth + 1));
            }

        return value[root];
    }
}
