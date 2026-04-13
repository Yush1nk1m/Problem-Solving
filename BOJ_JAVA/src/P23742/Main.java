package P23742;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static long[] a;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        a = new long[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            a[i] = Long.parseLong(tokens[i]);
    }

    private static void solve() {
        int i = N - 1;
        long sum = 0, size = 0;

        Arrays.sort(a);
        while (i >= 0 && a[i] >= 0) {
            sum += a[i--];
            ++size;
        }

        while (i >= 0) {
            if (sum * size + a[i] > (sum + a[i]) * (size + 1))
                break;
            sum += a[i--];
            ++size;
        }

        sum *= size;
        while (i >= 0)
            sum += a[i--];

        System.out.print(sum);
    }
}
