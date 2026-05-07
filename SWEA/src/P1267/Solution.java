package P1267;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, V, E;
    static int[] inDegree;
    static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        while (++T <= 10) {
            initialize();
            solve();
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        inDegree = new int[V + 1];
        graph = new List[V + 1];
        for (int i = 1; i <= V; ++i)
            graph[i] = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        while (E-- > 0) {
            int src = Integer.parseInt(st.nextToken());
            int dest = Integer.parseInt(st.nextToken());
            graph[src].add(dest);
            ++inDegree[dest];
        }
    }

    private static void solve() {
        sb.append('#').append(T);

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= V; ++i)
            if (inDegree[i] == 0)
                queue.offer(i);

        while (!queue.isEmpty()) {
            int curr = queue.poll();
            sb.append(' ').append(curr);

            for (int next : graph[curr])
                if (--inDegree[next] == 0)
                    queue.offer(next);
        }

        sb.append('\n');
    }
}
