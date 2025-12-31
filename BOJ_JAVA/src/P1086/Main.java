package P1086;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int NONE = -1;

    static int N, K;
    static long numerator, denominator, divisor;
    static int[][] conversionCache;
    static long[][] cache;
    static char[][] input;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        input = new char[N][];
        for (int i = 0; i < N; ++i)
            input[i] = br.readLine().toCharArray();
        conversionCache = new int[N][101];
        for (int[] row : conversionCache)
            Arrays.fill(row, NONE);
        cache = new long[1 << N][101];
        for (long[] row : cache)
            Arrays.fill(row, NONE);
        K = Integer.parseInt(br.readLine());

        numerator = DFS(0, 0);
        denominator = factorial(N);
        divisor = GCD(denominator, numerator);
        numerator /= divisor;
        denominator /= divisor;

        System.out.print(numerator + "/" + denominator);
    }

    public static long DFS(int mask, int remainder) {
        if (mask == (1 << N) - 1)
            return remainder == 0 ? 1L : 0L;
        else if (cache[mask][remainder] != NONE)
            return cache[mask][remainder];

        cache[mask][remainder] = 0L;
        for (int i = 0; i < N; ++i)
            if ((mask & (1 << i)) == 0)
                cache[mask][remainder] += DFS(mask | (1 << i), conversion(i, remainder));
        return cache[mask][remainder];
    }

    public static int conversion(int index, int base) {
        if (conversionCache[index][base] != NONE)
            return conversionCache[index][base];

        int value = base;
        for (char c : input[index]) {
            value *= 10;
            value += (c - '0');
            value %= K;
        }
        return conversionCache[index][base] = value;
    }

    public static long factorial(int number) {
        if (number <= 1)
            return number;
        return number * factorial(number - 1);
    }

    public static long GCD(long a, long b) {
        if (a < b) {
            long t = a;
            a = b;
            b = t;
        }
        if (b == 0)
            return a;

        while (a % b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return b;
    }
}
