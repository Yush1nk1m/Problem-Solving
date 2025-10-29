package P2313;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int n, len;
    static long total;
    static int[] value, min;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        while (n-- > 0)
            total += solve();
        System.out.println(total);
        System.out.println(sb);
    }

    public static long solve() throws IOException {
        len = Integer.parseInt(br.readLine());
        tokens = br.readLine().split(" ");
        value = new int[len + 1];
        min = new int[len + 1];
        int sum = Integer.MIN_VALUE, l = 0, r = 1_000_000_000;
        for (int i = 1; i < value.length; ++i) {
            value[i] = Integer.parseInt(tokens[i - 1]);
            value[i] += value[i - 1];
            min[i] = value[min[i - 1]] >= value[i] ? i : min[i - 1];
            if (sum < value[i] - value[min[i - 1]]) {
                sum = value[i] - value[min[i - 1]];
                l = min[i - 1];
                r = i;
            } else if (sum == value[i] - value[min[i - 1]] && r - l > i - min[i - 1]) {
                l = min[i - 1];
                r = i;
            }
        }
        sb.append(l + 1).append(' ').append(r).append('\n');
        return sum;
    }
}
