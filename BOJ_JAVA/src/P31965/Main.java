package P31965;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, Q;
    static long L, R;
    static long[] x, sum;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        Q = Integer.parseInt(tokens[1]);

        x = new long[N + 1];
        sum = new long[N + 1];
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            sum[i] = x[i] = Long.parseLong(tokens[i - 1]);
            sum[i] += sum[i - 1];
        }

        while (Q-- > 0) {
            tokens = br.readLine().split(" ");
            L = Long.parseLong(tokens[0]);
            R = Long.parseLong(tokens[1]);
            sb.append(query(L, R)).append('\n');
        }

        System.out.println(sb);
    }

    public static long query(long l, long r) {
        int leftIndex = Arrays.binarySearch(x, l);
        if (leftIndex < 0) leftIndex = -leftIndex - 1;
        int rightIndex = Arrays.binarySearch(x, r);
        if (rightIndex < 0) rightIndex = -rightIndex - 2;

        if (leftIndex >= rightIndex)
            return 0L;

        int middleIndex = (leftIndex + rightIndex) / 2;
        long minCost = Math.min(calcCost(leftIndex, rightIndex, middleIndex), calcCost(leftIndex, rightIndex, middleIndex + 1));
        long maxCost = Math.max(calcCost(leftIndex, rightIndex, leftIndex), calcCost(leftIndex, rightIndex, rightIndex));

        return maxCost - minCost;
    }

    public static long calcCost(int l, int r, int target) {
        return ((target - l + 1) * x[target] - (sum[target] - sum[l - 1]))
                + ((sum[r] - sum[target - 1]) - (r - target + 1) * x[target]);
    }
}
