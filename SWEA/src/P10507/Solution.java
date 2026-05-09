package P10507;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int MAX = 1000001;

    static int T, n, p;
    static int[] studied = new int[MAX + 1];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; ++i) {
            initialize();
            solve(i);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        Arrays.fill(studied, 0);
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i)
            studied[Integer.parseInt(st.nextToken()) + 1] = 1;
        for (int i = 1; i <= MAX; ++i)
            studied[i] += studied[i - 1];
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        int l = 1, h = n + p, period = 0;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (check(m)) {
                period = Math.max(period, m);
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        sb.append(period).append('\n');
    }

    private static boolean check(int size) {
        for (int end = size; end <= MAX; ++end)
            if (studied[end] - studied[end - size] + p >= size)
                return true;
        return false;
    }
}
