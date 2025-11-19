package P11666;

import java.io.*;
import java.util.*;

public class Main {

    static class Stamp {
        int start, end;

        public Stamp(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int n, m, a, s, saved;
    static List<Stamp> list = new ArrayList<>();
    static PriorityQueue<Stamp> appended;

    public static void main(String[] args) throws IOException {
        appended = new PriorityQueue<>(new Comparator<Stamp>() {
            public int compare(Stamp s1, Stamp s2) {
                return Integer.compare(s1.end, s2.end);
            }
        });
        tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        m = Integer.parseInt(tokens[1]);
        for (int i = 0; i < n; ++i) {
            tokens = br.readLine().split(" ");
            a = Integer.parseInt(tokens[0]);
            s = Integer.parseInt(tokens[1]);
            list.add(new Stamp(a, a + s));
        }
        list.sort(new Comparator<Stamp>() {
            public int compare(Stamp s1, Stamp s2) {
                return Integer.compare(s1.start, s2.start);
            }
        });
        Outer: for (Stamp stamp : list) {
            if (appended.isEmpty() || appended.peek().end > stamp.start) {
                appended.offer(stamp);
                continue Outer;
            }
            while (!appended.isEmpty()) {
                Stamp curr = appended.poll();
                if (curr.end + m >= stamp.start) {
                    ++saved;
                    break;
                }
            }
            appended.offer(stamp);
        }
        System.out.println(saved);
    }
}
