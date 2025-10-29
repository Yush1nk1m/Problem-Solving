package P20171;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String tokens[];

    static int n, k, i, j, root;
    static boolean[] visited;
    static List<List<Integer>> graph;
    static Set<Integer> apt = new HashSet<>();
    static List<Integer> result = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        k = Integer.parseInt(tokens[1]);

        visited = new boolean[n + 1];
        graph = new ArrayList<>(n + 1);
        for (int l = 0; l < n + 1; ++l)
            graph.add(new ArrayList<>());
        for (int l = 0; l < n - 1; ++l) {
            tokens = br.readLine().split(" ");
            i = Integer.parseInt(tokens[0]);
            j = Integer.parseInt(tokens[1]);
            graph.get(i).add(j);
            graph.get(j).add(i);
        }

        tokens = br.readLine().split(" ");
        for (int l = 0; l < k; l++)
            apt.add(Integer.parseInt(tokens[l]));

        root = Integer.parseInt(tokens[0]);
        DFS(root);

        System.out.println(result.size());
    }

    public static boolean DFS(int curr) {
        boolean reachable = false;
        visited[curr] = true;

        if (apt.contains(curr))
            reachable = true;

        for (int next : graph.get(curr))
            if (!visited[next] && DFS(next))
                reachable = true;

        if (reachable)
            result.add(curr);

        return reachable;
    }
}
