package P25515;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        long value;
        List<Integer> child = new ArrayList<>();
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int n, p, c;
    static Node[] nodes;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        nodes = new Node[n];
        for (int i = 0; i < n; ++i)
            nodes[i] = new Node();

        for (int i = 0; i < n - 1; ++i) {
            tokens = br.readLine().split(" ");
            p = Integer.parseInt(tokens[0]);
            c = Integer.parseInt(tokens[1]);
            nodes[p].child.add(c);
        }

        tokens = br.readLine().split(" ");
        for (int i = 0; i < n; ++i)
            nodes[i].value = Long.parseLong(tokens[i]);
    }

    private static void solve() {
        System.out.print(DFS(0));
    }

    private static long DFS(int index) {
        long sum = nodes[index].value;
        for (int next : nodes[index].child) {
            long val = DFS(next);
            if (val > 0)
                sum += val;
        }
        return sum;
    }
}
