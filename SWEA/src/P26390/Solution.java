package P26390;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int t, n;
    static int[] count;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            sb.append(solve()).append('\n');
        System.out.print(sb);
    }

    private static int solve() throws IOException {
        int ret = 0;
        n = Integer.parseInt(br.readLine());
        count = new int[n + 1];
        for (int i = 0; i < n - 1; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 2; ++j)
                if (++count[Integer.parseInt(st.nextToken())] >= 3)
                    ++ret;
        }
        return ret;
    }
}
