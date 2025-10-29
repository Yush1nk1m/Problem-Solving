package P1106;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;

    static int C, N;
    static int[] cost, effect;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        C = Integer.parseInt(tokens[0]);
        N = Integer.parseInt(tokens[1]);
        cost = new int[N];
        effect = new int[N];
        for (int i = 0; i < N; i++) {
            tokens = br.readLine().split(" ");
            cost[i] = Integer.parseInt(tokens[0]);
            effect[i] = Integer.parseInt(tokens[1]);
        }
        cache = new int[N][C + 1];
        for (int[] row : cache)
            Arrays.fill(row, INF);
        System.out.println(DFS(0, C));
    }

    public static int DFS(int index, int remained) {
        if (remained <= 0)
            return 0;
        else if (index >= N)
            return INF;
        else if (cache[index][remained] != INF)
            return cache[index][remained];

        for (int count = remained / effect[index] + (remained % effect[index] > 0 ? 1 : 0); count >= 0; count--)
            cache[index][remained] = Math.min(cache[index][remained], count * cost[index] + DFS(index + 1, remained - effect[index] * count));

        return cache[index][remained];
    }
}
