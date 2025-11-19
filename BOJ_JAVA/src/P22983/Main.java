package P22983;

import java.io.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = 0;

    static int N, M;
    static long sum;
    static char[][] table;
    static long[][] cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        table = new char[N][];
        for (int r = 0; r < N; ++r)
            table[r] = br.readLine().toCharArray();
        cache = new long[N][M];
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < M; ++c)
                sum += DFS(r, c);
        System.out.println(sum);
    }

    public static long DFS(int r, int c) {
        if (r == N - 1 || c == M - 1)
            return 1L;
        else if (cache[r][c] != NONE)
            return cache[r][c];

        cache[r][c] = Integer.MAX_VALUE;
        if (table[r][c] == table[r+1][c+1] && table[r+1][c] == table[r][c+1] && table[r][c] != table[r+1][c])
            return cache[r][c] = 1 + Math.min(DFS(r+1, c+1), Math.min(DFS(r+1, c), DFS(r, c+1)));
        else
            return cache[r][c] = 1;
    }
}
