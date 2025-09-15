package P1263;

import java.io.*;
import java.util.*;

class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static int[][] graph;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; i++)
            sb.append('#').append(i).append(' ').append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        graph = new int[N][N];
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++) {
                graph[r][c] = Integer.parseInt(st.nextToken());
                if (graph[r][c] == 0) graph[r][c] = 100_000_000;
            }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);

        int ret = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            graph[i][i] = 0;
            for (int dist : graph[i])
                sum += dist;
            ret = Math.min(ret, sum);
        }

        return ret;
    }
}
