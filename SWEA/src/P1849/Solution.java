package P1849;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N, M;
    static int[] parent, weight;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        weight = new int[N + 1];
        parent = new int[N + 1];
        for (int i = 1; i <= N; ++i)
            parent[i] = i;
    }

    private static void solve(int x) throws IOException {
        sb.append('#').append(x);
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            if (st.nextToken().equals("!"))
                append(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            else
                query(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        sb.append('\n');
    }

    private static void append(int a, int b, int diff) {
        if (find(a, b))
            return;
        union(a, b, diff);
    }

    private static boolean find(int a, int b) {
        Stack<Integer> stack = new Stack<>();

        while (a != parent[a]) {
            stack.push(a);
            a = parent[a];
        }
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            weight[curr] += weight[parent[curr]];
            parent[curr] = a;
        }

        while (b != parent[b]) {
            stack.push(b);
            b = parent[b];
        }
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            weight[curr] += weight[parent[curr]];
            parent[curr] = b;
        }

        return a == b;
    }

    private static void union(int a, int b, int diff) {
        int aw = weight[a], bw = weight[b];

        while (a != parent[a])
            a = parent[a];
        while (b != parent[b])
            b = parent[b];

        weight[b] = aw - bw + diff;
        parent[b] = a;
    }

    private static void query(int a, int b) {
        if (!find(a, b))
            sb.append(" UNKNOWN");
        else
            sb.append(' ').append(weight[b] - weight[a]);
    }
}
