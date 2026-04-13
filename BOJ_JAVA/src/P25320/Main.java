package P25320;

import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        String robot, operation;
        int id;
        Node next = null, previous = null;

        public Node() {
        }

        public Node(String robot, String operation, int id) {
            this.robot = robot;
            this.operation = operation;
            this.id = id;
        }

        public void addNext(Node node) {
            node.next = this.next;
            node.previous = this;
            this.next = node;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M;
    static Node head;
    static TreeSet<Integer> set = new TreeSet<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken()) - 1;

        for (int i = 1; i <= N << 1; ++i)
            set.add(i);

        st = new StringTokenizer(br.readLine());
        head = new Node(
                st.nextToken(),
                st.nextToken(),
                Integer.parseInt(st.nextToken())
        );
        set.remove(head.id);

        Node curr = head;
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            curr.addNext(new Node(
                    st.nextToken(),
                    st.nextToken(),
                    Integer.parseInt(st.nextToken())
            ));
            curr = curr.next;
            set.remove(curr.id);
        }
    }

    private static void solve() {
        if (!insertMinimalChain(head) || !insertMaximalChain(head)) {
            System.out.print("NO");
            return;
        }

        sb.append("YES\n");
        while (head != null) {
            sb.append(head.robot).append(' ').append(head.operation).append(' ').append(head.id).append('\n');
            head = head.next;
        }
        System.out.print(sb);
    }

    private static boolean insertMinimalChain(Node head) {
        while (head != null) {
            if (head.next != null && head.robot.equals(head.next.robot)) {
                if (set.higher(head.id) == null)
                    return false;
                Node next = new Node(head.robot.equals("A") ? "B" : "A", "CHAIN", set.higher(head.id));
                set.remove(next.id);
                head.addNext(next);
            } else if (head.next == null && head.robot.equals("A")) {
                if (set.higher(head.id) == null)
                    return false;
                Node next = new Node("B", "CHAIN", set.higher(head.id));
                set.remove(next.id);
                head.addNext(next);
            }
            head = head.next;
        }
        return true;
    }

    private static boolean insertMaximalChain(Node head) {
        while (head != null && !set.isEmpty()) {
            while (head.next != null && head.next.operation.equals("CHAIN"))
                head = head.next;

            while (set.higher(head.id) != null && set.higher(set.higher(head.id)) != null) {
                Node next = new Node(head.robot.equals("A") ? "B" : "A", "CHAIN", set.higher(head.id));
                set.remove(next.id);
                head.addNext(next);
                head = head.next;

                next = new Node(head.robot.equals("A") ? "B" : "A", "CHAIN", set.higher(head.id));
                set.remove(next.id);
                head.addNext(next);
                head = head.next;
            }

            head = head.next;
        }
        return set.isEmpty();
    }
}
