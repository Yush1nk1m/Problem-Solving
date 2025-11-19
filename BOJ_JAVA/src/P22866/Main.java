package P22866;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = 200001;

    static int N;
    static int[] height, visible;
    static int[] nearest;
    static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        height = new int[N];
        visible = new int[N];
        nearest = new int[N];
        Arrays.fill(nearest, NONE);
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            height[i] = Integer.parseInt(tokens[i]);
        for (int i = 0; i < N; ++i) {
            while (!stack.isEmpty() && height[stack.peek()] <= height[i])
                stack.pop();
            visible[i] += stack.isEmpty() ? 0 : stack.size();
            nearest[i] = stack.isEmpty() ? NONE : stack.peek();
            stack.add(i);
        }
        while (!stack.isEmpty())
            stack.pop();
        for (int i = N - 1; i >= 0; --i) {
            while (!stack.isEmpty() && height[stack.peek()] <= height[i])
                stack.pop();
            visible[i] += stack.isEmpty() ? 0 : stack.size();
            nearest[i] = stack.isEmpty() ? nearest[i] : Math.abs(i - nearest[i]) > Math.abs(i - stack.peek()) ? stack.peek() : nearest[i];
            stack.add(i);
        }
        for (int i = 0; i < N; ++i) {
            sb.append(visible[i]);
            if (visible[i] > 0)
                sb.append(' ').append(nearest[i] + 1);
            sb.append('\n');
        }
        System.out.println(sb);
    }
}
