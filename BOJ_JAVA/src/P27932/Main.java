package P27932;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int n, k;
    static int[] height;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        k = Integer.parseInt(tokens[1]);
        height = new int[n + 2];
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= n; ++i)
            height[i] = Integer.parseInt(tokens[i - 1]);
        height[0] = height[1];
        height[n + 1] = height[n];
        System.out.print(solve());
    }

    public static int solve() {
        int l = 0, h = 1_000_000_000, ret = 1_000_000_001;

        while (l <= h) {
            int m = (l + h) >> 1;
            if (check(m)) {
                ret = Math.min(ret, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ret;
    }

    public static boolean check(int diff) {
        int count = 0;
        for (int i = 1; i <= n; ++i)
            if (Math.abs(height[i] - height[i + 1]) > diff || Math.abs(height[i] - height[i - 1]) > diff)
                ++count;
        return count <= k;
    }
}
