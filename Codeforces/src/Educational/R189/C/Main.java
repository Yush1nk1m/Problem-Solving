package Educational.R189.C;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static int t, n;
    static char[][] table = new char[2][];
    static int[] cache;

    public static void main(String[] args) throws IOException{
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            initialize();
            solve();
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < 2; ++i)
            table[i] = br.readLine().toCharArray();
        cache = new int[n];
        Arrays.fill(cache, NONE);
    }

    private static void solve() {
        sb.append(DFS(0)).append('\n');
    }

    private static int DFS(int index) {
        if (index >= n)
            return 0;
        else if (cache[index] != NONE)
            return cache[index];

        cache[index] = Integer.MAX_VALUE;
        if (table[0][index] != table[1][index])
            cache[index] = Math.min(cache[index], 1 + DFS(index + 1));
        else
            cache[index] = Math.min(cache[index], DFS(index + 1));

        if (index + 1 < n) {
            int count = 0;
            if (table[0][index] != table[0][index + 1])
                ++count;
            if (table[1][index] != table[1][index + 1])
                ++count;
            cache[index] = Math.min(cache[index], count + DFS(index + 2));
        }

        return cache[index];
    }
}
