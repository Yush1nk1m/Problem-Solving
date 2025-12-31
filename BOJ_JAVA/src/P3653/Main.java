package P3653;

import java.io.*;

public class Main {

    static class Tree {
        int height, id, base;
        int[] tree, map;

        public Tree(int size, int expandable) {
            height = (int) Math.ceil(Math.log(size + expandable) / Math.log(2)) + 1;
            base = (1 << (height - 1));
            map = new int[size + 1];
            for (int i = size; i > 0; --i)
                map[i] = id++;
            tree = new int[1 << height];
            for (int i = 0; i < size; ++i)
                tree[base + i] = 1;
            for (int i = base - 1; i > 0; --i)
                tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }

        public void increment(int index) {
            index += base;
            while (index > 0) {
                ++tree[index];
                index >>= 1;
            }
        }

        public void decrement(int index) {
            index += base;
            while (index > 0) {
                --tree[index];
                index >>= 1;
            }
        }

        public int sum(int from) {
            int ret = 0;
            int to = base + id - 1;
            from += base + 1;
            while (from <= to) {
                if (from % 2 == 1)
                    ret += tree[from++];
                if (to % 2 == 0)
                    ret += tree[to--];
                from >>= 1;
                to >>= 1;
            }
            return ret;
        }

        public int pop(int number) {
            int ret = sum(map[number]);
            decrement(map[number]);
            map[number] = id++;
            increment(map[number]);
            return ret;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int t, n, m;
    static Tree tree;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            tokens = br.readLine().split(" ");
            n = Integer.parseInt(tokens[0]);
            m = Integer.parseInt(tokens[1]);
            tree = new Tree(n, m);
            tokens = br.readLine().split(" ");
            for (String token : tokens)
                sb.append(tree.pop(Integer.parseInt(token))).append(' ');
            sb.append('\n');
        }
        System.out.print(sb);
    }
}
