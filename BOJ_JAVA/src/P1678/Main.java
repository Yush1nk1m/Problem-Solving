package P1678;

import java.io.*;
import java.util.*;

public class Main {

    static class Train implements Comparable<Train> {
        String id;
        int arrival;

        public Train(String id, int arrival) {
            this.id = id;
            this.arrival = arrival;
        }

        public int compareTo(Train o) {
            return arrival - o.arrival;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int T, M, N, s = 0;
    static List<Train> trains = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        T = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        N = Integer.parseInt(tokens[2]);
        while (T-- > 0) {
            tokens = br.readLine().split(" ");
            for (int i = 1; i < tokens.length - 1; ++i)
                trains.add(new Train(tokens[0], Integer.parseInt(tokens[i])));
        }
        Collections.sort(trains);
        if (trains.get(trains.size() - 1).arrival >= M)
            while (trains.get(s).arrival < M)
                ++s;
    }

    private static void solve() {
        System.out.print(trains.get((s + (N - 1)) % trains.size()).id);
    }
}
