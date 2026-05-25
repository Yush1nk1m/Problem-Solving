package P8191;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static int[] numbers;
    static boolean[] visited;

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
        numbers = new int[N];
        visited = new boolean[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            numbers[i] = Integer.parseInt(st.nextToken());
    }

    private static void solve(int x) throws IOException {
        sb.append('#').append(x).append(' ');

        int count = 0;
        for (int number : numbers) {
            if (!visited[number - 1])
                ++count;
            visited[number] = true;
        }

        sb.append(count).append('\n');
    }
}
