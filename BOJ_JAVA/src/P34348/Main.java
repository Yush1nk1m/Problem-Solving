package P34348;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static String line;
    static int Q, l, r;
    static int[] s, n, u, p, c;
    static char[] chars = new char[]{'s', 'n', 'u', 'p', 'c'};

    public static void main(String[] args) throws IOException {
        line = br.readLine();
        s = new int[line.length() + 1];
        n = new int[line.length() + 1];
        u = new int[line.length() + 1];
        p = new int[line.length() + 1];
        c = new int[line.length() + 1];
        for (int i = 1; i <= line.length(); i++) {
            s[i] = s[i - 1] + ((line.charAt(i - 1) == 's') ? 1 : 0);
            n[i] = n[i - 1] + ((line.charAt(i - 1) == 'n') ? 1 : 0);
            u[i] = u[i - 1] + ((line.charAt(i - 1) == 'u') ? 1 : 0);
            p[i] = p[i - 1] + ((line.charAt(i - 1) == 'p') ? 1 : 0);
            c[i] = c[i - 1] + ((line.charAt(i - 1) == 'c') ? 1 : 0);
        }

        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            st = new StringTokenizer(br.readLine());
            l = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            sb.append(solve()).append('\n');
        }

        System.out.println(sb);
    }

    public static int solve() {
        int low = 1, high = (r - l + 1) / 5 + 1, ret = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (DFS(l - 1, mid, 0)) {
                ret = Math.max(ret, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ret;
    }

    public static boolean DFS(int i, int k, int depth) {
        if (depth == 5)
            return true;

        switch (chars[depth]) {
            case 's':
                i = binarySearch(s, i, r, s[i] + k);
                break;
            case 'n':
                i = binarySearch(n, i, r, n[i] + k);
                break;
            case 'u':
                i = binarySearch(u, i, r, u[i] + k);
                break;
            case 'p':
                i = binarySearch(p, i, r, p[i] + k);
                break;
            case 'c':
                i = binarySearch(c, i, r, c[i] + k);
                break;
        }
        if (i < 0)
            return false;

        return DFS(i, k, depth + 1);
    }

    public static int binarySearch(int[] arr, int l, int r, int target) {
        int ret = Integer.MAX_VALUE;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] > target) {
                r = m - 1;
            } else if (arr[m] < target) {
                l = m + 1;
            } else {
                ret = Math.min(ret, m);
                r = m - 1;
            }
        }
        return ret == Integer.MAX_VALUE ? -1 : ret;
    }
}
