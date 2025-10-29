package P17497;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static long N;
    static Stack<Character> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        N = Long.parseLong(br.readLine());
        if ((N & 1) != 0) {
            N <<= 1;
            stack.push('/');
        }
        while (N > 0) {
            if ((N & 2) != 0) {
                N -= 2;
                stack.add('+');
            } else {
                N >>= 1;
                stack.add('*');
            }
        }

        if (stack.size() > 99)
            sb.append(-1);
        else {
            sb.append(stack.size()).append('\n');
            while (!stack.isEmpty())
                sb.append("[").append(stack.pop()).append("] ");
        }
        System.out.println(sb);
    }
}
