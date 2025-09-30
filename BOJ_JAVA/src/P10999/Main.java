package P10999;

import java.io.*;
import java.util.*;

class Main {

    static class Node {
        long value, lazyValue;

        public Node(long value, long lazyValue) {
            this.value = value;
            this.lazyValue = lazyValue;
        }
    }

    static class Tree {
        Node[] tree;
        int leafPointer, leafSize;

        public Tree(int size) {
            int height = (int) Math.ceil(Math.log(size) / Math.log(2)) + 1;
            tree = new Node[(int) Math.pow(2, height)];
            for (int i = 0; i < tree.length; i++)
                tree[i] = new Node(0, 0);
            leafSize = leafPointer = (int) Math.pow(2, height - 1);
        }

        public long select(int from, int to) {
            return internalSelect(1, 1, leafSize, from, to);
        }

        private long internalSelect(int i, int lb, int ub, int from, int to) {
            propagate(i, lb, ub);
            if (i > tree.length || from > ub || to < lb)
                return 0L;
            else if (from <= lb && ub <= to)
                return tree[i].value;

            int mb = (lb + ub) / 2;
            return internalSelect(i * 2, lb, mb, from, to) + internalSelect(i * 2 + 1, mb + 1, ub, from, to);
        }

        public void update(int from, int to, long amount) {
            internalUpdate(1, 1, leafSize, from, to, amount);
        }

        private void internalUpdate(int i, int lb, int ub, int from, int to, long amount) {
            propagate(i, lb, ub);
            if (i >= tree.length || from > ub || to < lb)
                return;
            else if (from <= lb && ub <= to) {
                tree[i].lazyValue += amount;
                return;
            }

            int mb = (lb + ub) / 2;
            tree[i].value += (Math.min(to, ub) - Math.max(from, lb) + 1) * amount;
            internalUpdate(i * 2, lb, mb, from, to, amount);
            internalUpdate(i * 2 + 1, mb + 1, ub, from, to, amount);
        }

        private void propagate(int i, int lb, int ub) {
            long lazyValue = tree[i].lazyValue;
            tree[i].value += lazyValue * (ub - lb + 1);
            tree[i].lazyValue = 0;
            if (i * 2 < tree.length)
                tree[i * 2].lazyValue += lazyValue;
            if (i * 2 + 1 < tree.length)
                tree[i * 2 + 1].lazyValue += lazyValue;
        }

        public void insert(int i, long value) {
            tree[leafPointer + i].value = value;
        }

        public void initialize() {
            for (int i = leafPointer - 1; i > 0; --i)
                tree[i].value = tree[i * 2].value + tree[i * 2 + 1].value;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M, K, a, b, c;
    static long d;
    static Tree tree;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        tree = new Tree(N);
        for (int i = 0; i < N; i++)
            tree.insert(i, Long.parseLong(br.readLine()));
        tree.initialize();
        for (int i = 0; i < M + K; i++) {
            st = new StringTokenizer(br.readLine());
            if (Integer.parseInt(st.nextToken()) == 1) {
                b = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());
                d = Long.parseLong(st.nextToken());
                tree.update(b, c, d);
            } else {
                b = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());
                sb.append(tree.select(b, c)).append('\n');
            }
        }
        System.out.println(sb);
    }
}
