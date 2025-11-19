package P1563;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int MOD = 1_000_000;
    static final int NONE = -1;

    static int N;
    static int[][][] cache;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        cache = new int[N][2][3];
        for (int[][] mat : cache)
            for (int[] row : mat)
                Arrays.fill(row, NONE);
        System.out.println(DFS(0, 0, 0));
    }

    public static int DFS(int day, int late, int absent) {
        if (late == 2 || absent == 3)
            return 0;
        else if (day == N)
            return 1;
        else if (cache[day][late][absent] != NONE)
            return cache[day][late][absent];

        return cache[day][late][absent] = ((DFS(day + 1, late, 0) % MOD) + (DFS(day + 1, late + 1, 0) % MOD) + (DFS(day + 1, late, absent + 1))) % MOD;
    }
}
