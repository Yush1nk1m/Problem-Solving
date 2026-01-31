package P17225;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int time, color, count, required;

        public Node(int  time, int color, int count, int required) {
            this.time = time;
            this.color = color;
            this.count = count;
            this.required = required;
        }

        public int compareTo(Node other) {
            if (time == other.time)
                return Integer.compare(color, other.color);
            return Integer.compare(time, other.time);
        }

        public boolean pack() {
            time += required;
            return --count == 0;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int A, B, N, t, c, m, id;
    static Deque<Node> blue = new LinkedList<>(), red = new LinkedList<>();
    static List<Integer> sm = new ArrayList<>(), js = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
        System.out.print(sb);
    }

    public static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        A = Integer.parseInt(tokens[0]);
        B = Integer.parseInt(tokens[1]);
        N = Integer.parseInt(tokens[2]);
        while (N-- > 0) {
            tokens = br.readLine().split(" ");
            t = Integer.parseInt(tokens[0]);
            c = (int) tokens[1].charAt(0);
            m = Integer.parseInt(tokens[2]);
            if (c == (int) 'B') {
                if (!blue.isEmpty())
                    t = Math.max(t, blue.peekLast().time + blue.peekLast().count * A);
                blue.offerLast(new Node(t, c, m, A));
            }
            else {
                if (!red.isEmpty())
                    t = Math.max(t, red.peekLast().time + red.peekLast().count * B);
                red.offerLast(new Node(t, c, m, B));
            }
        }
    }

    public static void solve() {
        PriorityQueue<Node> pq = new PriorityQueue<>();

        if (!blue.isEmpty())
            pq.offer(blue.pollFirst());
        if (!red.isEmpty())
            pq.offer(red.pollFirst());

        while (!pq.isEmpty()) {
            Node node = pq.poll();
            if (node.color == (int) 'B')
                sm.add(++id);
            else
                js.add(++id);
            if (node.pack()) {
                if (node.color == (int) 'B' && !blue.isEmpty())
                    pq.offer(blue.pollFirst());
                else if (node.color == (int) 'R' && !red.isEmpty())
                    pq.offer(red.pollFirst());
            } else pq.offer(node);
        }

        sb.append(sm.size()).append('\n');
        for (int t : sm)
            sb.append(t).append(' ');
        sb.append('\n').append(js.size()).append('\n');
        for (int t : js)
            sb.append(t).append(' ');
    }
}
