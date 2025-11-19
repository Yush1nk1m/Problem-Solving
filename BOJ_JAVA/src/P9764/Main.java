package P9764;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static final int MOD = 100_999;

    static int T, N;
    static int[][] cache = new int[2001][2001];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            sb.append(DFS(N, 0)).append('\n');
        }
        System.out.println(sb);
    }

    public static int DFS(int curr, int sub) {
        if (curr == sub)
            return 0;
        else if (curr == 0)
            return 1;
        else if (cache[curr][sub] != 0)
            return cache[curr][sub];

        for (int s = sub + 1; s <= curr >> 1; ++s) {
            cache[curr][sub] += DFS(curr - s, s);
            cache[curr][sub] %= MOD;
        }
        cache[curr][sub] += DFS(0, curr);
        cache[curr][sub] %= MOD;
        return cache[curr][sub];
    }
}
