package P11737;

import java.io.*;
import java.util.*;

public class Solution {

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int[][] d = {
            {0, 0, 1, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {1, 0, 0, 1}
    };

    static int TC, n, a, b, id;

    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for (int x = 1; x <= TC; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        id = 1;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        sb.append(getDistance(
                buildTable(0, 0,0, 2, n, 1, a),
                buildTable(0, 0,0, 2, n, 1, b)
        )).append('\n');
    }

    private static Coords buildTable(int r, int c, int ri, int ci, int level, int from, int target) {
        int[] dr = d[ri], dc = d[ci];
        int gap = 1 << (level - 1);
        if (level == 0) {
            return new Coords(r, c);
        } else {
            int bucket;
            if (target < from + gap * gap) {
                bucket = 0;
            } else if (target < from + 2 * gap * gap) {
                bucket = 1;
            } else if (target < from + 3 * gap * gap) {
                bucket = 2;
            } else {
                bucket = 3;
            }

            int pr = r + dr[bucket] * gap, pc = c + dc[bucket] * gap;
            if (bucket == 0) {
                return buildTable(pr, pc, ci, ri, level - 1, from, target);
            } else if (bucket <= 2) {
                return buildTable(pr, pc, ri, ci, level - 1, from + gap * gap * bucket, target);
            } else {
                int nri = ci >= 2 ? 5 - ci : 1 - ci, nci = ri >= 2 ? 5 - ri : 1 - ri;
                return buildTable(pr, pc, nri, nci, level - 1, from + gap * gap * bucket, target);
            }
        }
    }

    private static long getDistance(Coords a, Coords b) {
        double r1 = (double) a.r, c1 = (double) a.c;
        double r2 = (double) b.r, c2 = (double) b.c;
        return (long) Math.round(Math.sqrt(Math.pow(10.0 * (r1 - r2), 2) + Math.pow(10.0 * (c1 - c2), 2)));
    }
}
