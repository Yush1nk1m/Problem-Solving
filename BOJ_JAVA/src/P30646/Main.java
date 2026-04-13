package P30646;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, count;
    static long[] numbers;
    static long maxSum = 0;
    static Map<Long, Integer> leftMap = new HashMap<>(), rightMap = new HashMap<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        numbers = new long[N + 1];
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i) {
            numbers[i] = Long.parseLong(tokens[i - 1]);
            if (!leftMap.containsKey(numbers[i]))
                leftMap.put(numbers[i], i);
        }
        for (int i = N; i > 0; --i)
            if (!rightMap.containsKey(numbers[i]))
                rightMap.put(numbers[i], i);
        for (int i = 1; i <= N; ++i)
            numbers[i] += numbers[i - 1];
    }

    private static void solve() {
        for (long key : leftMap.keySet())
            maxSum = Math.max(maxSum, numbers[rightMap.get(key)] - numbers[leftMap.get(key) - 1]);
        for (long key : leftMap.keySet())
            if (numbers[rightMap.get(key)] - numbers[leftMap.get(key) - 1] == maxSum)
                ++count;
        System.out.print(maxSum + " " + count);
    }
}
