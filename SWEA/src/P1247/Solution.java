package P1247;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

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

    static final int INF = Integer.MAX_VALUE;
    static final int COMPANY = 0;
    static final int HOME = 1;

    static int T, N;
    static Coords[] coords;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; i++)
            sb.append('#').append(i).append(' ').append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        N = Integer.parseInt(br.readLine());
        coords = new Coords[N + 2];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i <= N + 1; i++) {
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            coords[i] = new Coords(x, y);
        }
        cache = new int[N + 2][1 << N + 2];
        for (int[] row : cache)
            Arrays.fill(row, INF);
        return DFS(COMPANY, 3);
    }

    public static int DFS(int prev, int mask) {
        if (mask == (1 << N + 2) - 1)
            return coords[prev].getDistance(coords[HOME]);
        else if (cache[prev][mask] != INF)
            return cache[prev][mask];

        for (int i = 2; i < N + 2; i++)
            if ((mask & (1 << i)) == 0)
                cache[prev][mask] = Math.min(cache[prev][mask], coords[prev].getDistance(coords[i]) + DFS(i, mask | (1 << i)));

        return cache[prev][mask];
    }
}
