package P26261;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = 100_000_000;
    static final int INF = 200_001;

    static int N, X, K;
    static int[] A, cache;
    static List<Integer> pages = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        X = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);
        A = new int[N + 1];
        pages.add(0);
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; ++i) {
            A[i] = Integer.parseInt(tokens[i - 1]);
            A[i] += A[i - 1];
            if (i - K >= 0 && A[i] == A[i - K]) {
                pages.add(i);
            }
        }
        cache = new int[pages.size() + 1];
        Arrays.fill(cache, NONE);
        long result = DFS(0);
        System.out.println(result <= N ? result : -1);
    }

    public static int DFS(int prev) {
        int startPage = pages.get(prev) + 1;
        if (N - startPage < X)
            return 1;
        else if (prev == pages.size() - 1)
            return cache[prev] = INF;
        else if (cache[prev] != NONE)
            return cache[prev];

        int curr = binarySearch(pages, startPage + X - 1);
        if (prev >= curr || pages.get(curr) - startPage + 1 < K)
            return cache[prev] = INF;
        while (prev < curr) {
            int ret = DFS(curr--);
            if (ret != INF) {
                return cache[prev] = 1 + ret;
            }
        }

        return cache[prev] = INF;
    }

    public static int binarySearch(List<Integer> list, int target) {
        int l = 0, r = list.size() - 1, ret = Integer.MIN_VALUE;

        while (l <= r) {
            int m = (l + r) / 2;
            if (list.get(m) <= target) {
                ret = Math.max(ret, m);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ret == Integer.MIN_VALUE ? 0 : ret;
    }
}
