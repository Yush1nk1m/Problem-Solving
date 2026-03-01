package P18240;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        Node left, right;
        int index;

        public Node(int index) {
            this.index = index;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, id = 1;
    static int[] depth, table;
    static Queue<Node>[] nodeList;
    static Node root;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        depth = new int[N];
        table = new int[N];

        tokens = br.readLine().split(" ");
        for (int i = 1; i < N; ++i)
            depth[i] = Integer.parseInt(tokens[i - 1]);

        nodeList = new Queue[N];
        for (int i = 0; i < N; ++i)
            nodeList[i] = new LinkedList<>();
        root = new Node(0);
        nodeList[0].offer(root);
    }

    private static void solve() {
        if (!constructTree()) {
            sb.append("-1");
            return;
        }

        traversal(root);
        for (int i = 0; i < N; ++i)
            sb.append(table[i]).append(" ");
    }

    private static boolean constructTree() {
        for (int i = 1; i < N; ++i) {
            int d = depth[i];
            if (nodeList[d - 1].isEmpty())
                return false;

            Node parent = nodeList[d - 1].peek();
            if (parent.left == null) {
                parent.left = new Node(i);
                nodeList[d].offer(parent.left);
            } else {
                parent.right = new Node(i);
                nodeList[d].offer(parent.right);
                nodeList[d - 1].poll();
            }
        }

        return true;
    }

    private static void traversal(Node root) {
        if (root.left != null)
            traversal(root.left);
        table[root.index] = id++;
        if (root.right != null)
            traversal(root.right);
    }
}
