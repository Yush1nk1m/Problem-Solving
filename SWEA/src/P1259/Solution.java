package P1259;

import java.io.*;
import java.util.*;

public class Solution {

    static class Node {
        int left, right;

        public Node(int left, int right) {
            this.left = left;
            this.right = right;
        }

        public String toString() {
            return "(" + left + ", " + right + ")";
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static Node[] nodes;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        nodes = new Node[N];
        visited = new boolean[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            nodes[i] = new Node(
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()));
    }

    private static void solve(int x) {
        sb.append('#').append(x);
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            visited[i] = true;
            List<Integer> temp = DFS(i);
            if (list.size() < temp.size())
                list = temp;
            visited[i] = false;
        }
        for (int i = list.size() - 1; i >= 0; --i)
            sb.append(' ').append(nodes[list.get(i)].left).append(' ').append(nodes[list.get(i)].right);
        sb.append('\n');
    }

    private static List<Integer> DFS(int curr) {
        List<Integer> list = new ArrayList<>();

        for (int next = 0; next < N; ++next)
            if (!visited[next] && nodes[curr].right == nodes[next].left) {
                visited[next] = true;
                List<Integer> temp = DFS(next);
                if (list.size() < temp.size())
                    list = temp;
                visited[next] = false;
            }
        list.add(curr);

        return list;
    }
}
