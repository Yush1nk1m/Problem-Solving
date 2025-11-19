package P20551;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, M, D;
    static int[] A;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        A = new int[N];
        for (int i = 0; i < N; ++i)
            A[i] = Integer.parseInt(br.readLine());
        Arrays.sort(A);
        while (M-- > 0) {
            D = Integer.parseInt(br.readLine());
            sb.append(binarySearch(A, D)).append('\n');
        }
        System.out.println(sb);
    }

    public static int binarySearch(int[] arr, int target) {
        int l = 0, h = arr.length - 1, i = Integer.MAX_VALUE;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (arr[m] < target) {
                l = m + 1;
            } else if (arr[m] > target) {
                h = m - 1;
            } else {
                i = Math.min(i, m);
                h = m - 1;
            }
        }
        return i == Integer.MAX_VALUE ? -1 : i;
    }
}
