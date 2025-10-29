package P23835;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, Q, a, b, t;
    static List<List<Integer>> graph;
    static int[] delivered;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        delivered = new int[N + 1];
        visited = new boolean[N + 1];
        graph = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++)
            graph.add(new ArrayList<>(N + 1));
        for (int i = 0; i < N - 1; i++) {
            tokens = br.readLine().split(" ");
            a = Integer.parseInt(tokens[0]);
            b = Integer.parseInt(tokens[1]);
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            tokens = br.readLine().split(" ");
            t = Integer.parseInt(tokens[0]);
            if (t == 1)
                deliver(Integer.parseInt(tokens[1]), Integer.parseInt(tokens[2]));
            else
                sb.append(delivered[Integer.parseInt(tokens[1])]).append('\n');
        }
        System.out.println(sb);
    }

    public static void deliver(int src, int dest) {
        Arrays.fill(visited, false);
        visited[src] = true;
        DFS(src, dest, 0);
    }

    public static boolean DFS(int curr, int dest, int depth) {
        if (curr == dest) {
            delivered[curr] += depth;
            return true;
        }

        for (int next : graph.get(curr))
            if (!visited[next]) {
                visited[next] = true;
                if (DFS(next, dest, depth + 1)) {
                    delivered[curr] += depth;
                    return true;
                }
            }

        return false;
    }
}
