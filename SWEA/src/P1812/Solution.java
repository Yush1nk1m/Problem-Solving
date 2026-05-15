package P1812;

import java.io.*;
import java.util.*;

public class Solution {

    static class Tile implements Comparable<Tile> {
        int width, height;

        public Tile(int width, int height) {
            if (width > height) { int temp = width; width = height; height = temp; }
            this.width = width;
            this.height = height;
        }

        public List<Tile> split(int length) {
            List<Tile> list = new ArrayList<>();
            if (length < width)
                list.add(new Tile(width - length, height));
            if (length < height)
                list.add(new Tile(length, height - length));
            return list;
        }

        public int compareTo(Tile other) {
            return Integer.compare(other.width, width);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N, M;
    static Integer[] S;
    static PriorityQueue<Tile> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        S = new Integer[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            S[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(S, Collections.reverseOrder());
        pq.clear();
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        int count = 0;

        for (int k : S) {
            if (pq.isEmpty() || (1 << k) > pq.peek().width) {
                ++count;
                pq.offer(new Tile(M, M));
            }

            Tile tile = pq.poll();
            pq.addAll(tile.split(1 << k));
        }

        sb.append(count).append('\n');
    }
}
