package P20666;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int index;
        long cost;

        public Node(int index, long cost) {
            this.index = index;
            this.cost = cost;
        }

        public int compareTo(Node other) {
            return Long.compare(cost, other.cost);
        }
    }

    static class Game {
        long[] difficulty;
        List<List<Node>> adjusting = new ArrayList<>();
        PriorityQueue<Node> pq = new PriorityQueue<>();
        boolean[] visited;

        public Game(int size) {
            difficulty = new long[size + 1];
            visited = new boolean[size + 1];
            for (int i = 0; i <= size; ++i)
                adjusting.add(new ArrayList<>());
        }

        public void initialize(String[] tokens) {
            for (int i = 1; i < difficulty.length; ++i)
                difficulty[i] = Long.parseLong(tokens[i - 1]);
        }

        public void addAdjusting(int a, int b, long t) {
            adjusting.get(a).add(new Node(b, t));
            difficulty[b] += t;
        }

        public void prepareQueue() {
            for (int i = 1; i < difficulty.length; ++i)
                pq.offer(new Node(i, difficulty[i]));
        }

        public long clearGame() {
            while (visited[pq.peek().index])
                pq.poll();
            Node curr = pq.poll();
            visited[curr.index] = true;
            for (Node node : adjusting.get(curr.index))
                if (!visited[node.index]) {
                    difficulty[node.index] -= node.cost;
                    pq.offer(new Node(node.index, difficulty[node.index]));
                }
            return curr.cost;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, p, a, b;
    static long t, result = Long.MIN_VALUE;
    static Game game;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        game = new Game(N);
        tokens = br.readLine().split(" ");
        game.initialize(tokens);
        p = Integer.parseInt(br.readLine());
        while (p-- > 0) {
            tokens = br.readLine().split(" ");
            a = Integer.parseInt(tokens[0]);
            b = Integer.parseInt(tokens[1]);
            t = Long.parseLong(tokens[2]);
            game.addAdjusting(a, b, t);
        }
        game.prepareQueue();
        while (M-- > 0)
            result = Math.max(result, game.clearGame());
        System.out.println(result);
    }
}
