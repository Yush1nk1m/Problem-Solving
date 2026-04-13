package P25419;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;

    static int n, k;
    static boolean[] forbidden;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        k = Integer.parseInt(tokens[1]);
        forbidden = new boolean[n + 1];
        cache = new int[2][n + 1];
        for (int[] row : cache)
            Arrays.fill(row, NONE);

        tokens = br.readLine().split(" ");
        for (String token : tokens)
            forbidden[Integer.parseInt(token)] = true;
    }

    private static void solve() {
        System.out.print(DFS(1, 0));
    }

    private static int DFS(int turn, int number) {
        if (cache[turn][number] != NONE)
            return cache[turn][number];

        cache[turn][number] = turn == 1 ? 0 : 1;

        for (int next = number + 1; next <= number + k && next <= n; ++next)
            if (!forbidden[next]) {
                cache[turn][number] = turn == 1
                        ? Math.max(cache[turn][number], DFS(1 - turn, next))
                        : Math.min(cache[turn][number], DFS(1 - turn, next));
            }

        return cache[turn][number];
    }
}
