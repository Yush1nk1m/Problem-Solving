package P21611;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static class Node {
        int r, c, id;
        Node prev, next;

        public Node(int r, int c, int id) {
            this.r = r;
            this.c = c;
            this.id = id;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int[] dr = {-1, 1, 0, 0};
    static final int[] dc = {0, 0, -1, 1};

    static int N, M, d, s;
    static int[] e = new int[4];
    static Node head;
    static Node[][] table;
    static List<Coords> coords = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        table = new Node[N + 1][N + 1];
        head = table[N >> 1][N >> 1] = new Node(N >> 1, N >> 1, 0);
        for (int r = 0; r < N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < N; ++c) {
                int value = Integer.parseInt(st.nextToken());
                if (value > 0)
                    table[r][c] = new Node(r, c, value);
            }
        }

        coords.add(new Coords(N >> 1, N >> 1));
        int r = (N >> 1) - 1, c = (N >> 1) - 1, step = 2;
        while (r >= 0 && c >= 0) {
            for (int i = 0; i < step; ++i) {
                ++r;
                connectChain(r, c);
            }
            for (int i = 0; i < step; ++i) {
                ++c;
                connectChain(r, c);
            }
            for (int i = 0; i < step; ++i) {
                --r;
                connectChain(r, c);
            }
            for (int i = 0; i < step; ++i) {
                --c;
                connectChain(r, c);
            }
            --r;
            --c;
            step += 2;
        }
    }

    private static void connectChain(int r, int c) {
        if (table[r][c] != null) {
            int pr = coords.get(coords.size() - 1).r, pc = coords.get(coords.size() - 1).c;
            table[pr][pc].next = table[r][c];
            table[r][c].prev = table[pr][pc];
        }
        coords.add(new Coords(r, c));
    }

    private static int solve() throws IOException {
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            d = Integer.parseInt(st.nextToken()) - 1;
            s = Integer.parseInt(st.nextToken());

            for (int m = 1; m <= s; ++m) {
                int r = (N >> 1) + dr[d] * m, c = (N >> 1) + dc[d] * m;
                erase(r, c);
            }
            align();

            while (explode())
                align();

            transform();
            align();
        }

        return e[1] + 2 * e[2] + 3 * e[3];
    }

    private static void print(String msg) throws IOException {
        System.out.println(msg);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                System.out.print((table[r][c] == null ? "N" : table[r][c].id) + "\t");
            }
            System.out.println();
        }
        br.readLine();
    }

    private static void erase(int r, int c) {
        Node node = table[r][c];
        if (node != null) {
            node.prev.next = node.next;
            if (node.next != null)
                node.next.prev = node.prev;
        }
    }

    private static boolean explode() {
        boolean ret = false;
        Queue<Node> queue = new LinkedList<>();
        Node curr = head;

        while (curr != null) {
            queue.offer(curr);
            curr = curr.next;
            while (curr != null && queue.peek().id == curr.id) {
                queue.offer(curr);
                curr = curr.next;
            }
            if (queue.size() > 3) {
                ret = true;
                e[queue.peek().id] += queue.size();
                Node prev = queue.peek().prev;
                prev.next = curr;
                if (curr != null)
                    curr.prev = prev;
            }
            queue.clear();
        }

        return ret;
    }

    private static void transform() {
        List<Node> list = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();
        Node curr = head.next;

        while (curr != null) {
            Node prev = curr.prev;
            queue.offer(curr);
            curr = curr.next;
            while (curr != null && queue.peek().id == curr.id) {
                queue.offer(curr);
                curr = curr.next;
            }
            Node A = new Node(N, N, queue.size());
            Node B = new Node(N, N, queue.peek().id);
            list.add(A);
            list.add(B);
            queue.clear();
        }

        curr = head;
        curr.next = null;
        for (int i = 0; i < Math.min(N * N - 1, list.size()); ++i) {
            Node node = list.get(i);
            curr.next = node;
            node.prev = curr;
            curr = curr.next;
        }
    }

    private static void align() {
        int i = 0;
        Node curr = head;
        while (curr != null && i < N * N) {
            int r = coords.get(i).r, c = coords.get(i).c;
            table[curr.r][curr.c] = null;
            curr.r = r;
            curr.c = c;
            table[curr.r][curr.c] = curr;
            curr = curr.next;
            ++i;
        }
        if (curr != null)
            curr.next = null;
    }
}
