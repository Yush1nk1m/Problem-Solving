package P17612;

import java.io.*;
import java.util.*;

public class Main {

    static class Cart implements Comparable<Cart> {
        long id, weight;
        Counter counter;

        public Cart(long id, long weight) {
            this.id = id;
            this.weight = weight;
        }

        public void assignCounter(Counter counter) {
            this.counter = counter;
        }

        public int compareTo(Cart other) {
            if (counter == null || other.counter == null)
                return 0;
            if (counter.finish == other.counter.finish)
                return Long.compare(other.counter.id, counter.id);
            return Long.compare(counter.finish, other.counter.finish);
        }
    }

    static class Counter implements Comparable<Counter> {
        long id, finish;

        public Counter(long id, long finish) {
            this.id = id;
            this.finish = finish;
        }

        public int compareTo(Counter other) {
            if (finish == other.finish)
                return Long.compare(id, other.id);
            return Long.compare(finish, other.finish);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static long n, k, result;
    static Queue<Cart> queue = new LinkedList<>();
    static PriorityQueue<Counter> counters = new PriorityQueue<>();
    static List<Cart> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        n = Long.parseLong(tokens[0]);
        k = Long.parseLong(tokens[1]);
        for (int i = 0; i < n; ++i) {
            tokens = br.readLine().split(" ");
            long id = Long.parseLong(tokens[0]);
            long weight = Long.parseLong(tokens[1]);
            queue.offer(new Cart(id, weight));
        }
        for (int i = 1; i <= k; ++i)
            counters.offer(new Counter(i, 0));

        while (!queue.isEmpty()) {
            Cart cart = queue.poll();
            Counter counter = counters.poll();
            counter.finish += cart.weight;
            cart.assignCounter(counter);
            counters.offer(new Counter(counter.id, counter.finish));
            list.add(cart);
        }
        Collections.sort(list);

        for (int i = 0; i < list.size(); ++i)
            result += list.get(i).id * (long) (i + 1);

        System.out.println(result);
    }
}
