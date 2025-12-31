package P14384;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; ++i)
            sb.append("Case #").append(i).append(": ").append(solve(br.readLine().toCharArray())).append('\n');
        System.out.print(sb);
    }

    public static int solve(char[] arr) {
        int count = 0;
        Stack<Character> stack = new Stack<>();
        for (int i = arr.length - 1; i >= 0; --i) {
            if ((stack.isEmpty() && arr[i] == '-') || (!stack.isEmpty() && stack.peek() != arr[i]))
                ++count;
            stack.push(arr[i]);
        }
        return count;
    }
}
