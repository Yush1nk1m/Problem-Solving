package D;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int t, n, q, l, r;
    static int[] arr, turn, boundary;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            solve();
    }

    public static void solve() throws IOException {
        String[] tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        q = Integer.parseInt(tokens[1]);
        arr = new int[n + 1];
        turn = new int[n + 1];
        boundary = new int[n + 1];
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(tokens[i - 1]);
            turn[i] = arr[i] < 3 ? arr[i] - 1 : (int) Math.ceil(Math.log(arr[i] - 1) / Math.log(2));
            System.out.println("turn[" + arr[i] + "]: " + turn[i]);
            if ((int) Math.ceil(Math.log(arr[i] - 1) / Math.log(2)) != (int) Math.ceil(Math.log(arr[i]) / Math.log(2)))
                ++boundary[i];
            turn[i] += turn[i - 1];
            boundary[i] += boundary[i - 1];
        }
        while (q-- > 0) {
            tokens = br.readLine().split(" ");
            l = Integer.parseInt(tokens[0]);
            r = Integer.parseInt(tokens[1]);
            sb.append(query(l, r)).append('\n');
        }
    }

    public static int query(int l, int r) {
        System.out.println("turn = " + (turn[r] - turn[l - 1]) + ", remained one = " + (r - l) + ", boundary = " + (boundary[r] - boundary[l]));
        return 0;
    }
}
