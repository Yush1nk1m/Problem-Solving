package P24620;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int INF = 100_000_000;

    static int T, N, sum;
    static int[] numbers;
    static List<Integer> divisors = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            initialize();
            solve();
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        divisors.clear();
        sum = 0;

        N = Integer.parseInt(br.readLine());
        numbers = new int[N];

        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i) {
            numbers[i] = Integer.parseInt(tokens[i]);
            sum += numbers[i];
        }

        for (int d = 1; d <= (int) Math.sqrt(sum); ++d)
            if (sum % d == 0) {
                divisors.add(d);
                divisors.add(sum / d);
            }
    }

    private static void solve() {
        int minCoalesce = INF;

        for (int d : divisors)
            minCoalesce = Math.min(minCoalesce, check(d));

        sb.append(minCoalesce == INF ? 0 : minCoalesce).append('\n');
    }

    private static int check(int size) {
        int acc = 0, count = 0;

        for (int i = 0; i < N; ++i) {
            acc += numbers[i];
            if (acc > size)
                return INF;
            else if (acc == size)
                acc = 0;
            else
                ++count;
        }
        return count;
    }
}
