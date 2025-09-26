package P19585;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        char c;
        Node[] child;

        public Node(char c) {
            this.c = c;
            child = new Node['z' - 'a' + 2];
        }

        public Node getChild(char c) {
            return child[c - 'a'];
        }

        public boolean hasChild(char c) {
            return child[c - 'a'] != null;
        }

        public void markEnd() {
            child['z' - 'a' + 1] = new Node((char) 0);
        }

        public boolean hasEnd() {
            return child['z' - 'a' + 1] != null;
        }

        public Node addAndReturnChild(char c) {
            if (!hasChild(c))
                child[c - 'a'] = new Node(c);

            return child[c - 'a'];
        }

        public void addLines(String line) {
            Node curr = this;
            for (int i = 0; i < line.length(); i++)
                curr = curr.addAndReturnChild(line.charAt(i));
            curr.markEnd();
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int C, N, Q;
    static Node colorRoot = new Node((char) 0);
    static Set<String> nameSet = new HashSet<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        while (C-- > 0)
            colorRoot.addLines(br.readLine());
        while (N-- > 0)
            nameSet.add(br.readLine());
        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0)
            sb.append(solve(br.readLine()) ? "Yes" : "No").append('\n');

        System.out.println(sb);
    }

    public static boolean solve(String line) {
        int i = 0;
        Node curr = colorRoot;
        while (i < line.length()) {
            if (!curr.hasChild(line.charAt(i)))
                return false;
            curr = curr.getChild(line.charAt(i++));
            if (curr.hasEnd() && nameSet.contains(line.substring(i)))
                return true;
        }

        return false;
    }
}
