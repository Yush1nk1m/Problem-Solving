package P9092;

import java.io.*;
import java.util.*;

public class Solution {

    static class Coords {
        int x, y;

        public Coords(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getDistance(Coords other) {
            return Math.abs(x - other.x) + Math.abs(y - other.y);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static int TC, n, k, x, y;
    static int[][] cache;
    static Coords[] nodes;

    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for (int i = 1; i <= TC; ++i) {
            initialize();
            solve(i);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        cache = new int[n][k + 1];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
        nodes = new Coords[n];

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            nodes[i] = new Coords(x, y);
        }
    }

    private static void solve(int i) {
        sb.append('#').append(i).append(' ').append(DFS(0, k)).append('\n');
    }

    private static int DFS(int curr, int chance) {
        if (curr == n - 1)
            return 0;
        else if (cache[curr][chance] != NONE)
            return cache[curr][chance];

        cache[curr][chance] = nodes[curr].getDistance(nodes[curr + 1]) + DFS(curr + 1, chance);
        for (int jump = Math.min(chance + 1, n - 1 - curr); jump > 0; --jump)
            cache[curr][chance] = Math.min(cache[curr][chance],
                    nodes[curr].getDistance(nodes[curr + jump]) + DFS(curr + jump, chance - jump + 1));

        return cache[curr][chance];
    }
}
