package P7511;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int t, n, k, m, a, b;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; ++i) {
            initialize();
            sb.append("Scenario ").append(i).append(":\n");
            solve();
            sb.append('\n');
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        parent = new int[n];
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        k = Integer.parseInt(br.readLine());
        while (k-- > 0) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            union(a, b);
        }
    }

    private static void solve() throws IOException {
        m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            sb.append(find(a, b) ? "1\n" : "0\n");
        }
    }

    private static void union(int a, int b) {
        List<Integer> list = new ArrayList<>();

        while (a != parent[a]) {
            list.add(a);
            a = parent[a];
        }

        while (b != parent[b]) {
            list.add(b);
            b = parent[b];
        }
        list.add(b);

        for (int n : list)
            parent[n] = a;
    }

    private static boolean find(int a, int b) {
        while (a != parent[a])
            a = parent[a];
        while (b != parent[b])
            b = parent[b];
        return a == b;
    }
}
