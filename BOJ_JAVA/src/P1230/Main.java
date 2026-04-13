package P1230;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int NONE = -1;
    static final int INF = 1001;

    static char[] O, N;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        O = br.readLine().toCharArray();
        N = br.readLine().toCharArray();
        cache = new int[O.length][N.length];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static void solve() throws IOException {
        int len;
        if ((len = DFS(0, 0)) >= INF)
            System.out.print(-1);
        else
            System.out.print(len);
    }

    private static int DFS(int i, int j) {
        if (i >= O.length && j >= N.length)
            return 0;
        else if (i >= O.length)
            return 1;
        else if (j >= N.length)
            return INF;
        else if (cache[i][j] != NONE)
            return cache[i][j];
        else if (O[i] == N[j])
            return cache[i][j] = DFS(i + 1, j + 1);

        cache[i][j] = INF;
        for (int nj = j; nj < N.length; ++nj)
            if (O[i] == N[nj])
                cache[i][j] = Math.min(cache[i][j], 1 + DFS(i, nj));

        return cache[i][j];
    }
}
