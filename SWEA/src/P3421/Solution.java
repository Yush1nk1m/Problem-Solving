package P3421;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static int T, N, M;
    static Set<Integer>[] graph;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        cache = new int[N][1 << N];
        for (int[] vec : cache)
            Arrays.fill(vec, NONE);
        graph = new Set[N];
        for (int i = 0; i < N; ++i)
            graph[i] = new HashSet<>();
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            graph[a].add(b);
            graph[b].add(a);
        }
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ').append(DFS(0, 0)).append('\n');
    }

    private static int DFS(int curr, int mask) {
        if (curr == N)
            return 1;
        else if (cache[curr][mask] != NONE)
            return cache[curr][mask];

        int maskIfSelected = mask;
        for (int dependency : graph[curr])
            maskIfSelected |= 1 << dependency;
        return cache[curr][mask] =
                DFS(curr + 1, mask) +
                ((mask & (1 << curr)) == 0 ? DFS(curr + 1, maskIfSelected) : 0);
    }
}
