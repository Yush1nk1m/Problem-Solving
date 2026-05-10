package P1257;

import java.io.*;
import java.util.*;

public class Solution_Improved {

    static class Node {
        char value;
        Node[] next = new Node[26];

        public Node(char value) {
            this.value = value;
        }

        public void appendNext(char c) {
            if (next[c - 'a'] != null)
                return;
            next[c - 'a'] = new Node(c);
        }

        public Node getNext(char c) {
            return next[c - 'a'];
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T, K;
    static String line;
    static Set<String> set = new HashSet<>();
    static List<String> list = new ArrayList<>();
    static Node root;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        K = Integer.parseInt(br.readLine());
        line = br.readLine();
        set.clear();
        list.clear();
        root = new Node((char) 0);
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        for (int s = 0; s < line.length(); ++s) {
            Node curr = root;
            for (int e = s; e < line.length(); ++e) {
                curr.appendNext(line.charAt(e));
                curr = curr.getNext(line.charAt(e));
            }
        }
        String result = DFS(root);
        sb.append(result.equals("none") ? "none" : result.substring(1)).append('\n');
    }

    private static String DFS(Node curr) {
        StringBuilder builder = new StringBuilder().append(curr.value);
        if (K == 0)
            return builder.toString();

        for (int i = 0; i < 26; ++i)
            if (curr.next[i] != null) {
                --K;
                String ret = DFS(curr.next[i]);
                if (!ret.equals("none"))
                    return builder.append(ret).toString();
            }

        return "none";
    }
}
