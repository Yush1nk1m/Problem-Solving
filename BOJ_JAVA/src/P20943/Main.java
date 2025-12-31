package P20943;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final double INF = 1_000_000_001;

    static long N, a, b, c, count;
    static Map<Double, List<Long>> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        N = Long.parseLong(br.readLine());
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            a = Long.parseLong(tokens[0]);
            b = Long.parseLong(tokens[1]);
            c = Long.parseLong(tokens[2]);

            double gradient = getGradient(a, b);
            map.putIfAbsent(gradient, new ArrayList<>());
            map.get(gradient).add(c);
        }
        for (double key : map.keySet()) {
            count += map.get(key).size() * (N - map.get(key).size());
        }
        count >>= 1;
        System.out.println(count);
    }

    public static double getGradient(long a, long b) {
        if (a == 0)
            return 0;
        else if (b == 0)
            return a > 0 ? -INF : INF;

        long div = gcd(a, b);
        a /= div;
        b /= div;

        return (double) a / (double) b;
    }

    public static long gcd(long a, long b) {
        if (a < b) {
            long t = a;
            a = b;
            b = t;
        }

        while (a % b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }

        return b;
    }
}
