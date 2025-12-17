package P14267;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int n, m;
    static int[] w, compliment;
    static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        m = Integer.parseInt(tokens[1]);
        w = new int[n + 1];
        compliment = new int[n + 1];
        graph = new List[n + 1];
        for (int i = 1; i <= n; ++i)
            graph[i] = new ArrayList<>();
        tokens = br.readLine().split(" ");
        for (int i = 2; i <= n; ++i) {
            int j = Integer.parseInt(tokens[i - 1]);
            graph[j].add(i);
        }
        while (m-- > 0) {
            tokens = br.readLine().split(" ");
            w[Integer.parseInt(tokens[0])] += Integer.parseInt(tokens[1]);
        }
        DFS(1, 0);
        for (int i = 1; i <= n; ++i)
            sb.append(compliment[i]).append(' ');
        System.out.println(sb);
    }

    public static void DFS(int root, int c) {
        compliment[root] = c + w[root];
        for (int next : graph[root])
            DFS(next, c + w[root]);
    }
}
