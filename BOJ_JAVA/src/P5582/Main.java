package P5582;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int NONE = -1;

    static char[] s1, s2;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        s1 = br.readLine().toCharArray();
        s2 = br.readLine().toCharArray();
        cache = new int[s1.length][s2.length];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static void solve() {
        int length = 0;
        for (int i = 0; i < s1.length; ++i)
            for (int j = 0; j < s2.length; ++j)
                length = Math.max(length, DFS(i, j));
        System.out.print(length);
    }

    private static int DFS(int i1, int i2) {
        if (i1 >= s1.length || i2 >= s2.length)
            return 0;
        else if (s1[i1] != s2[i2])
            return cache[i1][i2] = 0;
        else if (cache[i1][i2] != NONE)
            return cache[i1][i2];

        return cache[i1][i2] = 1 + DFS(i1 + 1, i2 + 1);
    }
}
