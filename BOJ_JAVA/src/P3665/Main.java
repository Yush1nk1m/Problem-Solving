    package P3665;

    import java.io.*;
    import java.util.*;

    public class Main {

        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer st;
        static StringBuilder sb = new StringBuilder();

        static int t, n, m, a, b;
        static int[] order, indegree;
        static Set<Integer>[] graph;
        static Queue<Integer> queue;
        static List<Integer> list;

        public static void main(String[] args) throws IOException {
            t = Integer.parseInt(br.readLine());
            while (t-- > 0) {
                initialize();
                solve();
            }
            System.out.print(sb);
        }

        private static void initialize() throws IOException {
            n = Integer.parseInt(br.readLine());
            order = new int[n];
            indegree = new int[n + 1];
            list = new ArrayList<>();
            queue = new LinkedList<>();
            graph = new Set[n + 1];
            for (int i = 1; i <= n; ++i)
                graph[i] = new HashSet<>();

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; ++i)
                order[i] = Integer.parseInt(st.nextToken());
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    graph[order[i]].add(order[j]);
                    ++indegree[order[j]];
                }
            }

            m = Integer.parseInt(br.readLine());
            while (m-- > 0) {
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                if (!graph[a].contains(b)) { int t = a; a = b; b = t; }
                graph[a].remove(b);
                graph[b].add(a);
                --indegree[b];
                ++indegree[a];
            }
        }

        private static void solve() {
            for (int i = 1; i <= n; ++i)
                if (indegree[i] == 0)
                    queue.offer(i);

            if (queue.size() != 1) {
                sb.append("IMPOSSIBLE\n");
                return;
            }

            while (!queue.isEmpty()) {
                if (queue.size() > 1) {
                    sb.append("?\n");
                    return;
                }

                int curr = queue.poll();
                list.add(curr);
                for (int next : graph[curr])
                    if (--indegree[next] == 0)
                        queue.offer(next);
            }

            if (list.size() != n) {
                sb.append("IMPOSSIBLE\n");
            } else {
                for (int node : list)
                    sb.append(node).append(' ');
                sb.append('\n');
            }
        }
    }
