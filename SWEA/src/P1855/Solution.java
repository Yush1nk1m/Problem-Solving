package P1855;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static int[] depth;
    static int[][] parent;
    static List<List<Integer>> tree;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; i++)
            sb.append('#').append(i).append(' ').append(solve()).append('\n');
        System.out.println(sb);
    }

    public static long solve() throws IOException {
        initialize();
        long totalDistance = 0;
        List<Integer> visitedOrder = BFS();
        for (int i = 1; i < visitedOrder.size(); i++)
            totalDistance += getDistance(visitedOrder.get(i), visitedOrder.get(i - 1));
        return totalDistance;
    }

    public static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());

        parent = new int[N + 1][(int) Math.ceil(Math.log(N) / Math.log(2)) + 1];
        depth = new int[N + 1];
        tree = new ArrayList<>();
        for (int i = 0; i <= N; i++)
            tree.add(new ArrayList<>());

        st = new StringTokenizer(br.readLine());
        for (int c = 2; c <= N; c++) {
            int p = Integer.parseInt(st.nextToken());
            parent[c][0] = p;
            depth[c] = depth[p] + 1;
            tree.get(p).add(c);
        }

        for (int pow = 1; pow < parent[0].length; pow++)
            for (int c = 1; c <= N; c++)
                parent[c][pow] = parent[parent[c][pow - 1]][pow - 1];
    }

    public static int getDistance(int v1, int v2) {
        int lca = LCA(v1, v2);
        return depth[v1] + depth[v2] - 2 * depth[lca];
    }

    public static int LCA(int v1, int v2) {
        if (depth[v1] < depth[v2]) { int t = v1; v1 = v2; v2 = t; }

        while (depth[v1] != depth[v2]) {
            int diff = depth[v1] - depth[v2];
            int jump = (int) (Math.log(diff) / Math.log(2));
            v1 = parent[v1][jump];
        }

        while (v1 != v2) {
            int k = (int) (Math.log(depth[v1]) / Math.log(2));
            while (k > 0 && parent[v1][k] == parent[v2][k])
                k--;
            v1 = parent[v1][k];
            v2 = parent[v2][k];
        }

        return v1;
    }

    public static List<Integer> BFS() {
        List<Integer> sequence = new ArrayList<>();
        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(1);
        sequence.add(1);
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            for (int child : tree.get(curr)) {
                queue.offer(child);
                sequence.add(child);
            }
        }
        return sequence;
    }
}