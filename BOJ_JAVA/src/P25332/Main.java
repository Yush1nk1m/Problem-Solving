package P25332;

import java.io.*;
import java.util.*;

class Main {

    static class Node implements Comparable<Node> {
        int value, index;

        public Node(int value, int index) {
            this.value = value;
            this.index = index;
        }

        public int compareTo(Node other) {
            if (value == other.value)
                return Integer.compare(index, other.index);
            return Integer.compare(value, other.value);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static long count;
    static int[] sum;
    static List<Node> nodes = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        sum = new int[N + 1];
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i)
            sum[i] = Integer.parseInt(tokens[i - 1]);
        tokens = br.readLine().split(" ");
        nodes.add(new Node(0, 0));
        for (int i = 1; i <= N; ++i) {
            sum[i] -= Integer.parseInt(tokens[i - 1]);
            sum[i] += sum[i - 1];
            nodes.add(new Node(sum[i], i));
        }
        Collections.sort(nodes);
        for (int i = 1; i <= N; ++i)
            count += binarySearch(sum[i], i);
        System.out.println(count);
    }

    public static long binarySearch(int value, int index) {
        int l, h, m, lb = 200_001, ub = -1;

        l = 0;
        h = nodes.size() - 1;
        while (l <= h) {
            m = (l + h) >> 1;
            if (nodes.get(m).value < value) {
                l = m + 1;
            } else if (nodes.get(m).value > value) {
                h = m - 1;
            } else {
                lb = Math.min(lb, m);
                h = m - 1;
            }
        }
        if (lb == 200_001 || nodes.get(lb).index >= index)
            return 0;

        l = 0;
        h = nodes.size() - 1;
        while (l <= h) {
            m = (l + h) >> 1;
            if (nodes.get(m).value < value) {
                l = m + 1;
            } else if (nodes.get(m).value > value) {
                h = m - 1;
            } else if (nodes.get(m).index < index) {
                ub = Math.max(ub, m);
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ub - lb + 1;
    }
}
