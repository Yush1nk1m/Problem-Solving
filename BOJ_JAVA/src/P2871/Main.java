package P2871;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int index;
        boolean used;
        char character;

        public Node(int index, char character) {
            this.index = index;
            this.used = false;
            this.character = character;
        }

        public int compareTo(Node other) {
            if (character == other.character)
                return Integer.compare(other.index, index);
            return Character.compare(character, other.character);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int N, turn;
    static char[] line;
    static Deque<Node> deque = new ArrayDeque<>();
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    static StringBuilder[] builders = new StringBuilder[]{new StringBuilder(), new StringBuilder()};

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        line = br.readLine().toCharArray();
        for (int i = 0; i < N; ++i) {
            deque.offerLast(new Node(i, line[i]));
            pq.offer(deque.peekLast());
        }
        while (N-- > 0) {
            builders[turn].append(((turn == 0) ? pollFromDeque() : pollFromPriorityQueue()));
            turn = 1 - turn;
        }
        sb.append((builders[0].toString().compareTo(builders[1].toString()) > 0 ? "DA\n" : "NE\n")).append(builders[1].toString());
        System.out.print(sb);
    }

    public static char pollFromDeque() {
        while (deque.peekLast().used)
            deque.pollLast();
        deque.peekLast().used = true;
        return deque.pollLast().character;
    }

    public static char pollFromPriorityQueue() {
        while (pq.peek().used)
            pq.poll();
        pq.peek().used = true;
        return pq.poll().character;
    }
}
