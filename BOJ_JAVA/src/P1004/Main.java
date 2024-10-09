package P1004;

import java.util.*;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int T = sc.nextInt();
        while (T-- > 0) {
            solve();
        }
    }

    public static void solve() {
        int count = 0;

        Point begin = new Point(sc.nextDouble(), sc.nextDouble());
        Point end = new Point(sc.nextDouble(), sc.nextDouble());

        int n = sc.nextInt();
        while (n-- > 0) {
            int inDegree = 0;

            Point center = new Point(sc.nextDouble(), sc.nextDouble());
            Double r = sc.nextDouble();

            if (center.euclideanDistance(begin) <= r) {
                inDegree++;
            }
            if (center.euclideanDistance(end) <= r) {
                inDegree++;
            }

            if (inDegree == 1) {
                count++;
            }
        }

        System.out.println(count);
    }

    public static class Point {
        private final Double x;
        private final Double y;

        public Point(Double x, Double y) {
            this.x = x;
            this.y = y;
        }

        public Double getX() {
            return x;
        }

        public Double getY() {
            return y;
        }

        public Double euclideanDistance(Point other) {
            return Math.sqrt(Math.pow(x - other.getX(), 2) + Math.pow(y - other.getY(), 2));
        }
    }
}
