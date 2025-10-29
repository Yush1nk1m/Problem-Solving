package P6549;

import java.io.*;

public class Main {

    static class Node implements Comparable<Node> {
        long value;
        int index;

        public Node() {}

        public Node(long value, int index) {
            this.value = value;
            this.index = index;
        }

        public int compareTo(Node other) {
            if (value == other.value)
                return index - other.index;
            return Long.compare(value, other.value);
        }
    }

    static class Tree {
        int length, height, ptr;
        Node[] tree;
        private static Node nullNode = new Node(Long.MAX_VALUE, Integer.MAX_VALUE);

        public Tree(int length) {
            this.length = length;
            this.height = (int) Math.ceil(Math.log(length) / Math.log(2)) + 1;
            ptr = (int) Math.pow(2, height - 1);
            tree = new Node[ptr << 1];
            for (int i = ptr; i < tree.length; i++)
                tree[i] = new Node(Long.MAX_VALUE, 0);
        }

        public void initialize() {
            for (int i = 0; i < length; i++) {
                tree[ptr + i].value = Long.parseLong(tokens[i + 1]);
                tree[ptr + i].index = i;
            }
            for (int i = ptr - 1; i > 0; i--)
                tree[i] = tree[i << 1].compareTo(tree[(i << 1) + 1]) <= 0 ? tree[i << 1] : tree[(i << 1) + 1];
        }

        public Node search(int i, int lb, int ub, int s, int e) {
            if (ub < s || e < lb || i >= tree.length)
                return nullNode;
            else if (s <= lb && ub <= e)
                return tree[i];

            int mb = (lb + ub) / 2;
            Node left = search(i << 1, lb, mb, s, e);
            Node right = search((i << 1) + 1, mb + 1, ub, s, e);
            return left.compareTo(right) <= 0 ? left : right;
        }

        public long solve(int s, int e) {
            if (s == e)
                return tree[ptr + s].value;
            else if (s > e)
                return Integer.MIN_VALUE;

            Node minNode = search(1, 0, ptr - 1, s, e);
            long ret = minNode.value * (e - s + 1);
            ret = Math.max(ret, solve(s, minNode.index - 1));
            ret = Math.max(ret, solve(minNode.index + 1, e));
            return ret;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static Tree tree;

    public static void main(String[] args) throws IOException {
        while (true) {
            tokens = br.readLine().split(" ");
            if (tokens[0].equals("0"))
                break;
            N = Integer.parseInt(tokens[0]);
            tree = new Tree(N);
            tree.initialize();
            sb.append(tree.solve(0, N - 1)).append('\n');
        }
        System.out.println(sb);
    }
}
