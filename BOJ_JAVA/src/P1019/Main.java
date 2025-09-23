package P1019;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static String N;
    static long number, sub;
    static long[] count = new long[10];

    public static void main(String[] args) throws IOException {
        N = br.readLine();
        number = Long.parseLong(N);
        for (int n = 0; number > 0; ++n) {
            countNumbers(number % 10L, n);
            number /= 10L;
            sub = sub * 10 + 1;
        }
        count[0] -= sub;
        for (long n : count)
            sb.append(n).append(' ');
        System.out.println(sb);
    }

    public static void countNumbers(long k, long n) {
        for (int i = 0; i < 10; ++i)
            count[i] += k * n * (long) Math.pow(10, n - 1);
        for (int i = 0; i < k; ++i)
            count[i] += (long) Math.pow(10, n);
        count[(int) k] += (Long.parseLong(N) % (long) Math.pow(10, n)) + 1;
    }
}
