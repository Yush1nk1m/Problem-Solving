package P11281;

import java.io.*;
import java.util.*;

public class Main {

    static class Graph {
        int size, id;
        int[] identifier;
        boolean[] finished;
        List<Integer>[] graph;
        Stack<Integer> stack;
        List<List<Integer>> components;

        public Graph(int size) {
            this.size = size;
            graph = new List[(size << 1) + 1];
            for (int i = 0; i < graph.length; ++i)
                graph[i] = new ArrayList<>();
        }

        public void addEdge(int i, int j) {
            graph[i + size].add(j + size);
        }

        public List<List<Integer>> SCC() {
            id = 0;
            identifier = new int[(size << 1) + 1];
            finished = new boolean[(size << 1) + 1];
            stack = new Stack<>();
            components = new ArrayList<>();

            for (int i = 1; i <= size; ++i) {
                if (identifier[size - i] == 0)
                    DFS(size - i);
                if (identifier[size + i] == 0)
                    DFS(size + i);
            }

            return components;
        }

        public int DFS(int root) {
            identifier[root] = ++id;
            stack.push(root);

            int begin = identifier[root];
            for (int next : graph[root]) {
                if (identifier[next] == 0)
                    begin = Math.min(begin, DFS(next));
                else if (!finished[next])
                    begin = Math.min(begin, identifier[next]);
            }

            if (begin == identifier[root]) {
                List<Integer> list = new ArrayList<>();
                int node;
                do {
                    node = stack.pop();
                    list.add(node);
                    finished[node] = true;
                } while (node != root);
                components.add(list);
            }

            return begin;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static int N, M, i, j;
    static Graph graph;
    static List<List<Integer>> components;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        graph = new Graph(N);
        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            i = Integer.parseInt(tokens[0]);
            j = Integer.parseInt(tokens[1]);
            graph.addEdge(-i, j);
            graph.addEdge(-j, i);
        }
        solve();
        System.out.print(sb);
    }

    public static void solve() {
        boolean[] checked = new boolean[(N << 1) + 1];
        int[] value = new int[N + 1];
        Arrays.fill(value, NONE);
        components = graph.SCC();
        for (int i = components.size() - 1; i >= 0; --i) {
            List<Integer> component = components.get(i);
            for (int j = component.size() - 1; j >= 0; --j) {
                int number = component.get(j) - N;
                int absolute = Math.abs(number);
                checked[component.get(j)] = true;
                if (checked[N + absolute] && checked[N - absolute]) {
                    sb.append("0");
                    return;
                }
                if (value[absolute] == NONE)
                    value[absolute] = number > 0 ? 0 : 1;
            }
            for (int node : component)
                checked[node] = false;
        }
        sb.append("1\n");
        for (int i = 1; i <= N; ++i)
            sb.append(value[i]).append(' ');
    }
}
