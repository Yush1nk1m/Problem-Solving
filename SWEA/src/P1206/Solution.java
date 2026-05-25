package P1206;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] height;

    public static void main(String[] args) throws IOException {
        for (int x = 1; x <= 10; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        height = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            height[i] = Integer.parseInt(st.nextToken());
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        int count = 0;
        for (int i = 2; i < N - 2; ++i)
            count += Math.max(0, height[i] - Math.max(
                            Math.max(height[i - 1], height[i - 2]),
                            Math.max(height[i + 1], height[i + 2])));
        sb.append(count).append('\n');
    }
}
