package P1204;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, x;
    static int[] score = new int[101];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; ++i) {
            initialize();
            solve();
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        x = Integer.parseInt(br.readLine());
        Arrays.fill(score, 0);
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 1000; ++i)
            ++score[Integer.parseInt(st.nextToken())];
    }

    private static void solve() {
        sb.append('#').append(x).append(' ');
        int count = 0, maximum = 0;
        for (int s = 0; s <= 100; ++s)
            if (count <= score[s]) {
                count = score[s];
                maximum = s;
            }
        sb.append(maximum).append('\n');
    }
}
