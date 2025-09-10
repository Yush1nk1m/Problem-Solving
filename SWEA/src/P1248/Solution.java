package P1248;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, V, E, v1, v2;
    static List<List<Integer>> graph;
    static int[][] parent;
    static int[] depth, subtree;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; i++) {
            int[] result = solve();
            sb.append("#").append(i).append(' ').append(result[0]).append(' ').append(result[1]).append('\n');
        }
        System.out.println(sb);
    }

    public static int[] solve() throws IOException {
        initializeVariables();
        constructTree();
        int root = LCA();
        return new int[]{root, subtree[root]};
    }

    public static void initializeVariables() throws IOException {
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        v1 = Integer.parseInt(st.nextToken());
        v2 = Integer.parseInt(st.nextToken());

        graph = new ArrayList<>();
        for (int i = 0; i <= V; i++)
            graph.add(new ArrayList<>());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < E; i++) {
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            graph.get(p).add(c);
        }

        parent = new int[V + 1][(int) (Math.log(V + 1) / Math.log(2)) + 1];
        depth = new int[V + 1];
        subtree = new int[V + 1];
    }

    public static void constructTree() {
        DFS(1);
        for (int pow = 1; pow < parent[0].length; pow++)
            for (int node = 1; node <= V; node++)
                parent[node][pow] = parent[parent[node][pow - 1]][pow - 1];
    }

    public static int DFS(int curr) {
        subtree[curr] = 1;
        for (int next : graph.get(curr)) {
            depth[next] = depth[curr] + 1;
            subtree[curr] += DFS(next);
            parent[next][0] = curr;
        }
        return subtree[curr];
    }

    public static int LCA() {
        if (depth[v1] < depth[v2]) {
            int t = v1; v1 = v2; v2 = t;
        }

        int depthDiff = depth[v1] - depth[v2];
        while (depthDiff > 0) {
            int jump = (int) Math.floor(Math.log(depthDiff) / Math.log(2));
            v1 = parent[v1][jump];
            depthDiff -= (int) Math.pow(2, jump);
        }

        while (v1 != v2) {
            int jump = (int) (Math.log(depth[v1]) / Math.log(2));
            while (jump > 0 && parent[v1][jump] == parent[v2][jump])
                jump--;
            v1 = parent[v1][jump];
            v2 = parent[v2][jump];
        }

        return v1;
    }
}
