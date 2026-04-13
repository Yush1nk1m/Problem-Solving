package P32654;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int NONE = -1;

    static int N;
    static int[][] next, cache;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        next = new int[N + 1][2];
        cache = new int[N + 1][100];
        for (int[] row : cache)
            Arrays.fill(row, -1);

        for (int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            next[i][0] = Integer.parseInt(st.nextToken());
            next[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    private static int solve() {
        for (int k = 10; k < 100; ++k)
            if (DFS(1, k) != 1)
                return k;
        return -1;
    }

    private static int DFS(int number, int life) {
        if (life == 0)
            return number == 1 ? 1 : 0;
        else if (cache[number][life] != NONE)
            return cache[number][life];

        return cache[number][life] = Math.max(
                DFS(next[number][0], life - 1),
                DFS(next[number][1], life - 1)
        );
    }
}
