package P2158;

import java.io.*;
import java.util.*;

public class Main {

    static class Info implements Comparable<Info> {
        int r,  c;
        double time, velocity;

        public Info(int r, int c, double time, double velocity) {
            this.r = r;
            this.c = c;
            this.time = time;
            this.velocity = velocity;
        }

        public int compareTo(Info o) {
            if (time == o.time)
                return Double.compare(o.velocity, velocity);
            return Double.compare(time, o.time);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static double V;
    static int R, C;
    static int[][] height;
    static Info[][] cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        V = Double.parseDouble(tokens[0]);
        R = Integer.parseInt(tokens[1]);
        C = Integer.parseInt(tokens[2]);
        height = new int[R + 1][C + 1];
        cache = new Info[R + 1][C + 1];
        for (int r = 1; r <= R; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 1; c <= C; ++c) {
                height[r][c] = Integer.parseInt(tokens[c - 1]);
                cache[r][c] = new Info(r, c, Double.MAX_VALUE, Double.MIN_VALUE);
            }
        }
        System.out.print(solve());
    }

    public static double solve() {
        PriorityQueue<Info> pq = new PriorityQueue<>();

        cache[1][1] = new Info(1, 1, 0.0, V);
        pq.offer(cache[1][1]);
        while (!pq.isEmpty()) {
            Info info = pq.poll();

            for (int d = 0; d < 4; ++d) {
                int nr = info.r + dr[d], nc = info.c + dc[d];
                if (!isValidPoint(nr, nc))
                    continue;
                double time = info.time + (1.0 / info.velocity);
                double velocity = info.velocity * Math.pow(2, height[info.r][info.c] - height[nr][nc]);

                Info next = new Info(nr, nc, time, velocity);
                if (cache[nr][nc].compareTo(next) > 0) {
                    cache[nr][nc] = next;
                    pq.offer(cache[nr][nc]);
                }
            }
        }

        return cache[R][C].time;
    }

    public static boolean isValidPoint(int r, int c) {
        return 1 <= r && r <= R && 1 <= c && c <= C;
    }
}
