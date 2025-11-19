package P11558;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static int[] next = new int[10001];
    static boolean[] visited = new boolean[10001];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0)
            sb.append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; ++i)
            next[i] = Integer.parseInt(br.readLine());
        Arrays.fill(visited, false);
        int ret = DFS(1);
        return visited[N] ? ret : 0;
    }

    public static int DFS(int curr) {
        visited[curr] = true;

        if (curr == N)
            return 0;
        else if (visited[next[curr]])
            return 0;

        return 1 + DFS(next[curr]);
    }
}
