package P22984;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static double NONE = -1.0;

    static int N;
    static double[] p;
    static double[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        p = new double[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            p[i] = Double.parseDouble(tokens[i]);
        cache = new double[2][N];
        for (double[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static void solve() {
        if (N == 1) {
            System.out.print(p[0]);
            return;
        }
        System.out.print(p[0] * (1.0 + DFS(1, 1)) + (1 - p[0]) * DFS(0, 1));
    }

    private static double DFS(int prevOn, int index) {
        if (index >= N)
            return 0.0;
        else if (cache[prevOn][index] != NONE)
            return cache[prevOn][index];

        if (prevOn == 0)
            return cache[prevOn][index] =
                    p[index] * (2.0 + DFS(1, index + 1)) + (1 - p[index]) * DFS(0, index + 1);
        else
            return cache[prevOn][index] =
                    p[index] * (1.0 + DFS(1, index + 1)) + (1 - p[index]) * (1.0 + DFS(0, index + 1));
    }
}
