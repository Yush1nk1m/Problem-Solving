package P11578;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100000000;
    static final int NONE = Integer.MAX_VALUE;

    static int N, M, O, allSolved, ret;
    static int[] solvable;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        allSolved = (1 << N) - 1;
        solvable = new int[M];
        cache = new int[1 << M][1 << N];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
        for (int i = 0; i < M; i++) {
            int mask = 0;
            tokens = br.readLine().split(" ");
            O = Integer.parseInt(tokens[0]);
            for (int j = 1; j <= O; j++)
                mask |= (1 << (Integer.parseInt(tokens[j]) - 1));
            solvable[i] = mask;
        }
        ret = DFS(0, 0);
        if (ret > M)
            System.out.println(-1);
        else
            System.out.println(ret);
    }

    public static int DFS(int visited, int mask) {
        if (mask == allSolved)
            return 0;
        else if (cache[visited][mask] != NONE)
            return cache[visited][mask];
        else if (visited == (1 << M) - 1)
            return INF;

        for (int i = 0; i < M; i++)
            if ((visited & (1 << i)) == 0)
                cache[visited][mask] = Math.min(cache[visited][mask], 1 + DFS(visited | (1 << i), mask | solvable[i]));

        return cache[visited][mask];
    }
}
