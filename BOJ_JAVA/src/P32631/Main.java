package P32631;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, K;
    static long[][] bags = new long[2][];
    static long[][] table = new long[2][];

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);

        bags[0] = new long[N + 1];
        bags[1] = new long[N + 1];
        table[0] = new long[K + 1];
        table[1] = new long[K + 1];

        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i)
            bags[0][i] = Long.parseLong(tokens[i - 1]) + bags[0][i - 1];

        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i)
            bags[1][i] = Long.parseLong(tokens[i - 1]) + bags[1][i - 1];
    }

    private static long solve() {
        for (int i = 0; i <= K; ++i) {
            table[0][i] = findMinSum(bags[0], N - i);
            table[1][i] = findMinSum(bags[1], N - i);
        }

        long ret = Long.MAX_VALUE;
        for (int i = 0; i <= K; ++i)
            ret = Math.min(ret, Math.max(table[0][i], table[1][K - i]));

        return ret;
    }

    private static long findMinSum(long[] bag, int size) {
        long sum = Long.MAX_VALUE;
        for (int i = size; i <= N; ++i)
            sum = Math.min(sum, bag[i] - bag[i - size]);
        return sum;
    }
}
