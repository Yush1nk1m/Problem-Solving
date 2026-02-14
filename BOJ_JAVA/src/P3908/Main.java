package P3908;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int BOUND = 1121;
    static final int NONE = -1;

    static int T, n, k;
    static boolean[] sieve = new boolean[BOUND];
    static List<Integer> prime = new ArrayList<>();
    static int[][][] cache;

    public static void main(String[] args) throws IOException {
        preprocess();
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            tokens = br.readLine().split(" ");
            n = Integer.parseInt(tokens[0]);
            k = Integer.parseInt(tokens[1]);
            sb.append(DFS(n, k, 0)).append('\n');
        }
        System.out.print(sb);
    }

    public static void preprocess() {
        for (int i = 2; i < BOUND; ++i)
            if (!sieve[i]) {
                sieve[i] = true;
                prime.add(i);
                for (int j = i << 1; j < BOUND; j += i)
                    sieve[j] = true;
            }

        cache = new int[BOUND][15][prime.size()];
        for (int[][] mat : cache)
            for (int[] row : mat)
                Arrays.fill(row, NONE);
    }

    public static int DFS(int number, int count, int index) {
        if (count == 0)
            return number == 0 ? 1 : 0;
        else if (number <= 0)
            return 0;
        else if (index >= prime.size())
            return 0;
        else if (cache[number][count][index] != NONE)
            return cache[number][count][index];

        return cache[number][count][index] =
                DFS(number, count, index + 1) + DFS(number - prime.get(index), count - 1, index + 1);
    }
}
