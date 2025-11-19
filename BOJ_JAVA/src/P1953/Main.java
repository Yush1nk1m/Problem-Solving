package P1953;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int n, t;
    static boolean[] visited;
    static List<Integer>[] team = new List[2];
    static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 2; ++i)
            team[i] = new ArrayList<>();
        n = Integer.parseInt(br.readLine());
        graph = new List[n + 1];
        for (int i = 1; i <= n; ++i)
            graph[i] = new ArrayList<>();
        visited = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            tokens = br.readLine().split(" ");
            for (int j = 1; j <= Integer.parseInt(tokens[0]); ++j) {
                graph[i].add(Integer.parseInt(tokens[j]));
                graph[Integer.parseInt(tokens[j])].add(i);
            }
        }
        for (int i = 1; i <= n; ++i)
            if (!visited[i]) {
                DFS(i, t);
                t = 1 - t;
            }

        for (List<Integer> row : team)
            Collections.sort(row);
        sb.append(team[0].size()).append('\n');
        for (int node : team[0])
            sb.append(node).append(' ');
        sb.append('\n').append(team[1].size()).append('\n');
        for (int node : team[1])
            sb.append(node).append(' ');
        System.out.println(sb);
    }

    public static void DFS(int node, int t) {
        visited[node] = true;
        team[t].add(node);
        for (int next : graph[node])
            if (!visited[next])
                DFS(next, 1 - t);
    }
}
