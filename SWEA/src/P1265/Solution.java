package P1265;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T;
    static long N, P;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            solve(x);
        }
        System.out.print(sb);
    }

    private static void solve(int x) throws IOException {
        sb.append('#').append(x).append(' ');
        st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        P = Long.parseLong(st.nextToken());

        long multiply = 1;
        while (P > 0) {
            multiply *= N / P;
            N -= N / P;
            --P;
        }

        sb.append(multiply).append('\n');
    }
}
