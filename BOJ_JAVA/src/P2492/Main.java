package P2492;

import java.io.*;
import java.util.*;

public class Main {

    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M, T, K, A, B;
    static List<Point> points = new ArrayList<>();
    static Set<Integer> xSet = new HashSet<>(), ySet = new HashSet<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            xSet.add(Math.min(A, N - K));
            ySet.add(Math.min(B, M - K));
            points.add(new Point(A, B));
        }
    }

    private static void solve() {
        int x = 0, y = 0, maxCount = 0;
        for (int bx : xSet)
            for (int by : ySet) {
                int count = 0;
                for (Point point : points)
                    if (bx <= point.x && point.x <= bx + K && by <= point.y && point.y <= by + K)
                        ++count;
                if (maxCount < count) {
                    maxCount = count;
                    x = bx;
                    y = by + K;
                }
            }

        System.out.print(x + " " + y + "\n" + maxCount);
    }
}
