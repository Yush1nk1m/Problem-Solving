package P24701;

import java.io.*;
import java.util.*;

public class Solution {

    static class Group {
        List<Integer> nodes = new ArrayList<>();
        List<Group> subGroups = null;
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;
    static final int OPENED = 0;
    static final int BLOCKED = 1;
    static final long[][] C = new long[51][51];

    static int T, N, lock;
    static long result;
    static int[][] graph;
    static boolean[] visited;
    static Group root, end;

    public static void main(String[] args) throws IOException {
        preprocessing();
        T = Integer.parseInt(br.readLine());
        while (T-- > 0)
            sb.append(solve()).append('\n');
        System.out.println(sb);
    }

    public static void preprocessing() {
        for (int n = 0; n <= 50; n++) {
            C[n][0] = C[n][n] = 1L;
            for (int r = 1; r <= n; r++)
                C[n][r] = C[n-1][r-1] + C[n-1][r];
        }
    }

    public static long solve() throws IOException {
        N = Integer.parseInt(br.readLine());
        result = 0;
        lock = 0;
        graph = new int[N + 1][N + 1];
        for (int[] row : graph)
            Arrays.fill(row, NONE);
        visited = new boolean[N + 1];
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int status = Integer.parseInt(st.nextToken());
            graph[u][v] = graph[v][u] = status;
        }

        root = grouping(1);
        --lock;

        if (root != end) {
            DFS(root, lock, 0, 1);
            result *= (long) Math.pow(2, end.nodes.size() - 1);
        } else {
            result = (long) Math.pow(2, root.nodes.size() - 1);
        }

        return result;
    }

    public static Group grouping(int node) {
        ++lock;
        Group g = new Group();
        List<Integer> nextRoots = new ArrayList<>();
        List<Group> subGroups = new ArrayList<>();
        Queue<Integer> queue = new ArrayDeque<>();

        visited[node] = true;
        queue.offer(node);
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            if (curr == N)
                end = g;
            g.nodes.add(curr);

            for (int ngbr = 1; ngbr <= N; ngbr++)
                if (!visited[ngbr]) {
                    if (graph[curr][ngbr] == OPENED) {
                        visited[ngbr] = true;
                        queue.offer(ngbr);
                    }
                    else if (graph[curr][ngbr] == BLOCKED)
                        nextRoots.add(ngbr);
                }
        }

        for (int nextRoot : nextRoots)
            subGroups.add(grouping(nextRoot));
        g.subGroups = subGroups;

        return g;
    }

    public static void DFS(Group root, int lock, int key, long total) {
        int n = root.nodes.size();
        int gs = root.subGroups.size();
        if (root.subGroups.contains(end))
            --gs;
        if (key < 0) {
            return;
        } else if (gs <= 0) {
            for (int i = n; i >= Math.max(lock, 0); i--)
                result += total * C[n][i];
            return;
        } else if (lock <= 0) {
            for (Group subGroup : root.subGroups)
                if (subGroup != end)
                    DFS(subGroup, lock, key, total * (long) Math.pow(2, n));
            return;
        }

        for (int r = 0; r <= n; r++)
            for (Group subGroup : root.subGroups)
                if (subGroup != end) {
                    DFS(subGroup, lock - r, key - gs + r, total * C[n][r]);
                }
    }
}
