package P17299;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] A, NGF, count = new int[1000001];
    static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        NGF = new int[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i) {
            A[i] = Integer.parseInt(tokens[i]);
            ++count[A[i]];
        }
    }

    private static void solve() {
        for (int i = 0; i < N; ++i) {
            if (stack.isEmpty()) {
                stack.push(i);
                continue;
            }

            while (!stack.isEmpty() && count[A[stack.peek()]] < count[A[i]])
                NGF[stack.pop()] = A[i];
            stack.push(i);
        }
        while (!stack.isEmpty())
            NGF[stack.pop()] = -1;

        for (int i = 0; i < N; ++i)
            sb.append(NGF[i]).append(' ');

        System.out.print(sb);
    }
}
