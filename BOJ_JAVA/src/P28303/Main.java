package P28303;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static long K;
    static long[] arr, rarr, leftMin, rightMin;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        arr = new long[N];
        rarr = new long[N];
        leftMin = new long[N];
        rightMin = new long[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            arr[i] = rarr[i] = leftMin[i] = rightMin[i] = Long.parseLong(st.nextToken());
        for (int i = 1; i < N; ++i) {
            arr[i] += K * i;
            rarr[N - 1 - i] += K * i;
        }
        rightMin[N - 1] = arr[N - 1];
        leftMin[0] = rarr[0];
        for (int i = 1; i < N; ++i) {
            rightMin[N - i - 1] = Math.min(arr[N - i - 1], rightMin[N - i]);
            leftMin[i] = Math.min(rarr[i], leftMin[i - 1]);
        }
    }

    private static void solve() {
        long result = Long.MIN_VALUE;
        for (int i = 0; i < N - 1; ++i) {
            result = Math.max(result, arr[i] - rightMin[i + 1]);
            result = Math.max(result, rarr[N - 1 - i] - leftMin[N - 2 - i]);
        }
        System.out.print(result);
    }
}
