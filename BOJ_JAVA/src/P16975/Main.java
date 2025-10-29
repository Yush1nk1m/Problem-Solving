package P16975;

import java.io.*;
import java.util.*;

class Main {

    static class Tree {
        long[] tree, lazy;
        int length, ptr;

        public Tree(int length) {
            this.length = length;
            int height = (int) Math.ceil(Math.log(length) / Math.log(2));
            ptr = (int) Math.pow(2, height + 1);
            tree = new long[ptr * 2];
            lazy = new long[ptr * 2];
        }

        public void initialize() throws IOException {
            tokens = br.readLine().split(" ");
            for (int i = 0; i < length; i++)
                tree[ptr + i] = Long.parseLong(tokens[i]);
            for (int i = ptr - 1; i >= 1; --i)
                tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }

        public void update(int start, int end, long value) {
            internalUpdate(1, 1, ptr, start, end, value);
        }

        public void internalUpdate(int index, int lb, int ub, int start, int end, long value) {
            if (index >= tree.length)
                return;
            propagate(index, lb, ub);
            if (start <= lb && ub <= end) {
                lazy[index] += value;
                return;
            } else if (start > ub || lb > end) {
                return;
            }

            int mb = (lb + ub) / 2;
            internalUpdate(index * 2, lb, mb, start, end, value);
            internalUpdate(index * 2 + 1, mb + 1, ub, start, end, value);
        }

        public long get(int x) {
            return internalSearch(1, 1, ptr, x, x);
        }

        public long internalSearch(int index, int lb, int ub, int start, int end) {
            if (index >= tree.length)
                return Long.MIN_VALUE;
            propagate(index, lb, ub);
            if (start <= lb && ub <= end) {
                return tree[index];
            } else if (start > ub || lb > end) {
                return 0L;
            }

            int mb = (lb + ub) / 2;
            return internalSearch(index * 2, lb, mb, start, end) + internalSearch(index * 2 + 1, mb + 1, ub, start, end);
        }

        public void propagate(int index, int lb, int ub) {
            int rangeLength = ub - lb + 1;
            tree[index] += lazy[index] * rangeLength;
            if (index * 2 < tree.length)
                lazy[index * 2] += lazy[index];
            if (index * 2 + 1 < tree.length)
                lazy[index * 2 + 1] += lazy[index];
            lazy[index] = 0;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, M, i, j, k, x;
    static Tree tree;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        tree = new Tree(N);
        tree.initialize();
        M = Integer.parseInt(br.readLine());
        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            if (Integer.parseInt(tokens[0]) == 1)
                tree.update(
                        Integer.parseInt(tokens[1]),
                        Integer.parseInt(tokens[2]),
                        Long.parseLong(tokens[3])
                );
            else
                sb.append(tree.get(Integer.parseInt(tokens[1]))).append('\n');
        }
        System.out.println(sb);
    }
}
