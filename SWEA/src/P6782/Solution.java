package P6782;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T;
    static long N;
    static TreeSet<Long> set = new TreeSet<>();

    public static void main(String[] args) throws IOException {
        for (long i = 2; i * i <= 1_000_002_000_001L; ++i)
            set.add(i * i);
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            N = Long.parseLong(br.readLine());
            solve(x);
        }
        System.out.print(sb);
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        long count = 0;
        while (N != 2) {
            if (Math.ceil(Math.sqrt(N)) == Math.floor(Math.sqrt(N))) {
                ++count;
                N = (long) Math.sqrt(N);
            } else {
                count += set.higher(N) - N;
                N = set.higher(N);
            }
        }
        sb.append(count).append('\n');
    }
}
