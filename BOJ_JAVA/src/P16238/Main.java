package P16238;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;

    static int N;
    static int[] count;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        count = new int[N + 2];

        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i)
            count[i] = Integer.parseInt(tokens[i - 1]);

        cache = new int[N + 2][N + 2];
    }

    private static int solve() {
        clearCache();
        int ret1 = DFS(0, 0);
        clearCache();
        int ret2 = RDFS(N + 1, 0);
        return Math.max(ret1, ret2);
    }

    private static void clearCache() {
        for (int[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static int DFS(int index, int day) {
        if (index >= N || day >= N)
            return 0;
        else if (cache[index][day] != NONE)
            return cache[index][day];

        cache[index][day] = 0;
        for (int i = index + 1; i <= N; ++i)
            if (count[i] - day > 0)
                cache[index][day] = Math.max(cache[index][day], count[i] - day + DFS(i, day + 1));

        return cache[index][day];
    }

    private static int RDFS(int index, int day) {
        if (index <= 1 || day >= N)
            return 0;
        else if (cache[index][day] != NONE)
            return cache[index][day];

        cache[index][day] = 0;
        for (int i = index - 1; i > 0; --i)
            if (count[i] - day > 0)
                cache[index][day] = Math.max(cache[index][day], count[i] - day + DFS(i, day + 1));

        return cache[index][day];
    }
}
