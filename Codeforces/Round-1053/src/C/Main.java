package C;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int t, n;
    static long[] prefix, prefixEven;
    static List<Long> result;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve();
            for (long x : result)
                sb.append(x).append(' ');
            sb.append('\n');
        }
        System.out.println(sb);
    }

    public static void solve() throws IOException {
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        prefix = new long[2 * n + 1];
        prefixEven = new long[2 * n + 1];
        result = new ArrayList<>();

        prefix[1] = prefixEven[1] = Long.parseLong(st.nextToken());
        prefix[2] = prefixEven[2] = Long.parseLong(st.nextToken());
        prefix[2] += prefix[1];
        for (int i = 3; i <= 2 * n; i++) {
            prefix[i] = prefixEven[i] = Long.parseLong(st.nextToken());
            prefix[i] += prefix[i - 1];
            prefixEven[i] += prefixEven[i - 2];
        }

        for (int k = 1; k <= n; k++) {
            long sub = 0, add = 0;
            int l = k, h = 2 * n - k;
            sub += prefix[l];
            add += prefix[2 * n] - prefix[h];
            if (l < h) {
                sub += prefixEven[k + 2 * (n - k)] - prefixEven[k];
                add += prefixEven[h - 1] - prefixEven[l - 1];
            }
            result.add(add - sub);
        }
    }
}
