package P26838;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final long NONE = -1L;

    static int TC, N, M, K;
    static int[] color;
    static List<Integer>[] graph;
    static long[][] cache;

    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        while (TC-- > 0) {
            initialize();
            solve();
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        color = new int[N];
        graph = new List[N];
        for (int i = 0; i < N; ++i)
            graph[i] = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            color[i] = Integer.parseInt(st.nextToken()) - 1;

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            graph[x].add(y);
            graph[y].add(x);
        }

        cache = new long[N][1 << K];
        for (long[] vec : cache)
            Arrays.fill(vec, NONE);
    }

    private static void solve() {
        long count = 0;
        for (int i = 0; i < N; ++i)
            count += DFS(i, 1 << color[i]);
        sb.append(count).append('\n');
    }

    private static long DFS(int curr, int mask) {
        if (cache[curr][mask] != NONE)
            return cache[curr][mask];

        cache[curr][mask] = 0;
        for (int next : graph[curr])
            if ((mask & (1 << color[next])) == 0)
                cache[curr][mask] += 1L + DFS(next, mask | (1 << color[next]));
        return cache[curr][mask];
    }
}
