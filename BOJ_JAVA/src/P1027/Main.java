package P1027;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final double INF = 1_000_000_001.0;

    static int N;
    static double[] height;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        height = new double[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            height[i] = Double.parseDouble(tokens[i]);
    }

    private static void solve() {
        int maxCount = 0;
        for (int i = 0; i < N; ++i) {
            double maxGradient = -INF, gradient;
            int j = i - 1, count = 0;

            while (j >= 0) {
                if ((gradient = -calcGradient(i, j)) > maxGradient) {
                    maxGradient = gradient;
                    ++count;
                }
                --j;
            }

            j = i + 1;
            maxGradient = -INF;

            while (j < N) {
                if ((gradient = calcGradient(i, j)) > maxGradient) {
                    maxGradient = gradient;
                    ++count;
                }
                ++j;
            }

            maxCount = Math.max(maxCount, count);
        }

        System.out.print(maxCount);
    }

    private static double calcGradient(int i, int j) {
        return (height[i] - height[j]) / (double) (i - j);
    }
}
