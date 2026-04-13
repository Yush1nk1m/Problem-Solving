package P22775;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int id;
        Node left, right;
        boolean leftNull = true;

        public void addChild(Node child) {
            if (leftNull) {
                left = child;
                leftNull = false;
            } else {
                right = child;
            }
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int i;
    static String line;
    static Node root;

    public static void main(String[] args) throws IOException {
        while (!(line = br.readLine()).equals("()"))
            solve();
        System.out.print(sb);
    }

    private static void solve() {
        parseTree();
        inorder(root);
        preorder(root);
        sb.append('\n');
    }

    private static void parseTree() {
        Stack<Node> stack = new Stack<>();
        root = new Node();
        stack.push(root);
        for (int i = 1; i < line.length(); ++i)
            if (line.charAt(i) == '(') {
                Node node = new Node();
                stack.peek().addChild(node);
                stack.push(node);
            } else if (line.charAt(i) == ')') {
                stack.pop();
            } else if (line.charAt(i) == ',' && stack.peek().leftNull) {
                stack.peek().leftNull = false;
            }
        i = 0;
    }

    private static void inorder(Node root) {
        if (root.left != null)
            inorder(root.left);
        root.id = ++i;
        if (root.right != null)
            inorder(root.right);
    }

    private static void preorder(Node root) {
        sb.append(root.id).append(' ');
        if (root.left != null)
            preorder(root.left);
        if (root.right != null)
            preorder(root.right);
    }
}
