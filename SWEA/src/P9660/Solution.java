package P9660;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final long MOD = 1_000_000_007L;
    static final long NONE = -1L;

    static int T, N;
    static long count;
    static long[] hate, factorial, cache;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        factorial = new long[N + 1];
        factorial[0] = 1;
        for (int i = 1; i <= N; ++i)
            factorial[i] = (factorial[i - 1] * (long) i) % MOD;
        count = factorial[N];

        hate = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) {
            int number = Integer.parseInt(st.nextToken());
            if (number <= N)
                ++hate[number];
        }

        cache = new long[N + 1];
        cache[0] = 1L;
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        for (int i = 1; i <= N; ++i)
            for (int chance = N; chance > 0; --chance) {
                cache[chance] += cache[chance - 1] * hate[i];
                cache[chance] %= MOD;
            }
        for (int chance = 1; chance <= N; ++chance) {
            if (chance % 2 != 0) {
                count -= cache[chance] * factorial[N - chance];
                if (count < 0) count += MOD;
            } else {
                count += cache[chance] * factorial[N - chance];
            }
            count %= MOD;
        }
        sb.append(count).append('\n');
    }
}
