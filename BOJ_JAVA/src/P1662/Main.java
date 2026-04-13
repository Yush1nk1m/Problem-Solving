package P1662;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        char value;
        int count;

        public Node(char value, int count) {
            this.value = value;
            this.count = count;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int count;
    static char[] line;
    static Stack<Node> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        line = br.readLine().toCharArray();
    }

    private static void solve() throws IOException {
        for (char c : line) {
            if (c != ')')
                stack.push(new Node(c, 1));
            else {
                int length = 0;
                while (!stack.isEmpty() && stack.peek().value != '(')
                    length += stack.pop().count;
                stack.pop();
                stack.peek().count = (stack.peek().value - '0') * length;
            }
        }
        while (!stack.isEmpty())
            count += stack.pop().count;

        System.out.print(count);
    }
}
