package P31864;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords implements Comparable<Coords> {
        double x, y, gradient;

        public Coords(double x, double y) {
            this.x = x;
            this.y = y;
            this.gradient = x == 0 ? INF : y / x;
        }

        public int compareTo(Coords other) {
            if (this.x == other.x)
                return Double.compare(this.y, other.y);
            return Double.compare(this.x, other.x);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;
    static final double INF = 1_000_000_001;

    static int N, M, s, e, result;
    static double x, y, gradient;
    static Map<Double, List<Coords>> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        while (N-- > 0) {
            tokens = br.readLine().split(" ");
            x = Double.parseDouble(tokens[0]);
            y = Double.parseDouble(tokens[1]);
            Coords coords = new Coords(x, y);
            if (!map.containsKey(coords.gradient))
                map.put(coords.gradient, new ArrayList<>());
            map.get(coords.gradient).add(coords);
        }
        for (double key : map.keySet())
            Collections.sort(map.get(key));
        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            x = Double.parseDouble(tokens[0]);
            y = Double.parseDouble(tokens[1]);
            gradient = x == 0 ? INF : y / x;
            if (!map.containsKey(gradient))
                continue;
            if (x > 0 && (s = GEBinarySearchX(map.get(gradient), 0)) != NONE && (e = LEBinarySearchX(map.get(gradient), x)) != NONE)
                result = Math.max(result, e - s + 1);
            else if (x < 0 && (s = LEBinarySearchX(map.get(gradient), 0)) != NONE && (e = GEBinarySearchX(map.get(gradient), x)) != NONE)
                result = Math.max(result, s - e + 1);
            else if (x == 0 && y > 0 && (s = GEBinarySearchY(map.get(gradient), 0)) != NONE && (e = LEBinarySearchY(map.get(gradient), y)) != NONE)
                result = Math.max(result, e - s + 1);
            else if (x == 0 && y < 0 && (s = LEBinarySearchY(map.get(gradient), 0)) != NONE && (e = GEBinarySearchY(map.get(gradient), y)) != NONE)
                result = Math.max(result, s - e + 1);
        }
        System.out.println(result);
    }

    public static int LEBinarySearchX(List<Coords> list, double x) {
        int l = 0, h = list.size() - 1, i = Integer.MIN_VALUE;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (list.get(m).x <= x) {
                i = Math.max(i, m);
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return i == Integer.MIN_VALUE ? NONE : i;
    }

    public static int GEBinarySearchX(List<Coords> list, double x) {
        int l = 0, h = list.size() - 1, i = Integer.MAX_VALUE;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (list.get(m).x >= x) {
                i = Math.min(i, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return i == Integer.MAX_VALUE ? NONE : i;
    }

    public static int LEBinarySearchY(List<Coords> list, double y) {
        int l = 0, h = list.size() - 1, i = Integer.MIN_VALUE;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (list.get(m).y <= y) {
                i = Math.max(i, m);
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return i == Integer.MIN_VALUE ? NONE : i;
    }

    public static int GEBinarySearchY(List<Coords> list, double y) {
        int l = 0, h = list.size() - 1, i = Integer.MAX_VALUE;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (list.get(m).y >= y) {
                i = Math.min(i, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return i == Integer.MAX_VALUE ? NONE : i;
    }
}
