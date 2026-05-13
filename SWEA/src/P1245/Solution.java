package P1245;

import java.io.*;
import java.util.*;

public class Solution {

    static class Point implements Comparable<Point> {
        double x, mass;

        public int compareTo(Point other) {
            return Double.compare(x, other.x);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N, x, mass;
    static Point[] points;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; ++i) {
            initialize(i);
            solve();
        }
        System.out.print(sb);
    }

    private static void initialize(int i) throws IOException {
        sb.append('#').append(i);

        N = Integer.parseInt(br.readLine());
        points = new Point[N];

        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; ++j) {
            points[j] = new Point();
            points[j].x = Double.parseDouble(st.nextToken());
        }
        for (int j = 0; j < N; ++j)
            points[j].mass = Double.parseDouble(st.nextToken());
        Arrays.sort(points);
    }

    private static void solve() {
        for (int i = 1; i < N; ++i) {
            double lx = points[i - 1].x, rx = points[i].x, x = 0.0;
            do {
                double mx = (lx + rx) / 2.0;
                double power = check(mx, i);
                x = mx;
                if (power < 0.0) {
                    lx = mx;
                } else if (power > 0.0) {
                    rx = mx;
                } else break;
            } while (rx - lx >= 1e-12);
            sb.append(' ').append(String.format("%.10f", x));
        }
        sb.append('\n');
    }

    private static double check(double x, int r) {
        double power = 0.0;
        for (int i = r; i < N; ++i) {
            double mass = points[i].mass;
            double distance = points[i].x - x;
            power += mass / Math.pow(distance, 2);
        }
        for (int i = 0; i < r; ++i) {
            double mass = points[i].mass;
            double distance = x - points[i].x;
            power -= mass / Math.pow(distance, 2);
        }

        return power;
    }
}
