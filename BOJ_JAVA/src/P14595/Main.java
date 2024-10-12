package P14595;

import java.io.*;
import java.util.*;

public class Main {

    private static int N, M, prevX, prevY;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static List<Pair> pairs;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        pairs = new ArrayList<>(M);
        for (int i = 0; i < M; i++) {
            String[] coordination = br.readLine().split(" ");
            pairs.add(new Pair(Integer.parseInt(coordination[0]), Integer.parseInt(coordination[1])));
        }
        pairs.sort(null);

        for (Pair pair : pairs) {
            if (prevY < pair.getX()) {
                N -= (prevY - prevX);
                prevX = pair.getX();
                prevY = pair.getY();
            } else {
                prevY = Math.max(prevY, pair.getY());
            }
        }
        N -= (prevY - prevX);

        bw.write(Integer.valueOf(N).toString());
        bw.flush();
        bw.close();
    }

    public static class Pair implements Comparable<Pair> {
        private final Integer x;
        private final Integer y;

        public Pair(Integer x, Integer y) {
            this.x = x;
            this.y = y;
        }

        public Integer getX() {
            return x;
        }

        public Integer getY() {
            return y;
        }

        @Override
        public int compareTo(Pair other) {
            if (x.equals(other.getX())) {
                return Integer.compare(y, other.getY());
            }
            return Integer.compare(x, other.getX());
        }
    }
}
