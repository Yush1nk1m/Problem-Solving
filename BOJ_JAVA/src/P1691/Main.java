package P1691;

import java.io.*;
import java.util.*;

public class Main {

    static class Plate {
        int width, height;

        public Plate(int width, int height) {
            this.width = width;
            this.height = height;
        }

        public boolean isFit(int width, int height) {
            return this.width <= width && this.height <= height;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;

    static int W, H, N;
    static int[][] cache;
    static List<Plate> plates = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        W = Integer.parseInt(tokens[0]);
        H = Integer.parseInt(tokens[1]);
        N = Integer.parseInt(br.readLine());
        cache = new int[W + 1][H + 1];
        for (int[] row : cache)
            Arrays.fill(row, INF);
        while (N-- > 0) {
            tokens = br.readLine().split(" ");
            int width = Integer.parseInt(tokens[0]);
            int height = Integer.parseInt(tokens[1]);
            plates.add(new Plate(width, height));
        }
        System.out.print(DFS(W, H));
    }

    public static int DFS(int width, int height) {
        if (width == 0 || height == 0)
            return 0;
        else if (cache[width][height] != INF)
            return cache[width][height];

        cache[width][height] = width * height;
        for (Plate plate : plates)
            if (plate.isFit(width, height)) {
                cache[width][height] = Math.min(
                        cache[width][height],
                        Math.min(
                                DFS(width - plate.width, plate.height) + DFS(width, height - plate.height),
                                DFS(width - plate.width, height) + DFS(plate.width, height - plate.height)
                        )
                );
            }

        return cache[width][height];
    }
}
