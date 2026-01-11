package P11280;

import java.io.*;
import java.util.*;

public class Main {

    static class Graph {
        int size, id;
        int[] identifier;
        Set<Integer>[] graph;
        List<List<Integer>> components;
        Stack<Integer> stack;
        boolean[] finished;

        public Graph(int size) {
            this.size = size;
            graph = new Set[(size << 1) + 1];
            for (int i = 0; i < graph.length; ++i)
                graph[i] = new HashSet<>();
        }

        public void addEdge(int i, int j) {
            graph[i + size].add(j + size);
        }

        public List<List<Integer>> SCC() {
            id = 0;
            identifier = new int[(size << 1) + 1];
            components = new ArrayList<>();
            finished = new boolean[(size << 1) + 1];
            stack = new Stack<>();

            for (int i = 1; i <= size; ++i) {
                if (identifier[i + size] == 0)
                    DFS(i + size);
                if (identifier[-i + size] == 0)
                    DFS(-i + size);
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

    static int N, M, i, j;
    static Graph graph;

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
        System.out.print(solve(graph.SCC()));
    }

    public static int solve(List<List<Integer>> components) {
        boolean[] checked = new boolean[(N << 1) + 1];
        for (List<Integer> component : components) {
            for (int node : component) {
                checked[node] = true;
                int gap = Math.abs(N - node);
                if (checked[N - gap] && checked[N + gap])
                    return 0;
            }

            for (int node : component) {
                checked[node] = false;
            }
        }
        return 1;
    }
}
