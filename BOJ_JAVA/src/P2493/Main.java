package P2493;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] height, receiver;
    static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        height = new int[N];
        receiver = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            height[i] = Integer.parseInt(st.nextToken());
    }

    private static void solve() {
        for (int i = N - 1; i >= 0; --i) {
            while (!stack.isEmpty() && height[stack.peek()] <= height[i])
                receiver[stack.pop()] = i + 1;
            stack.push(i);
        }
        for (int i : receiver)
            sb.append(i).append(' ');

        System.out.print(sb);
    }
}
