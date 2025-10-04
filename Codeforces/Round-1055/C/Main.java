package C;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static final int MATCH = 1;

    static int t, n, q;
    static int[] arr, sum, match;
    static List<Integer> oneIndices;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            solve();
        System.out.println(sb);
    }

    public static void solve() throws IOException {
        String[] tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        q = Integer.parseInt(tokens[1]);
        arr = new int[n + 1];
        sum = new int[n + 1];
        match = new int[n + 1];
        oneIndices = new ArrayList<>();
        tokens =  br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            sum[i] = arr[i] = Integer.parseInt(tokens[i - 1]);
            sum[i] += sum[i - 1];
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i + 1])
                match[i] = MATCH;
            match[i] += match[i - 1];
        }
        while (q-- > 0) {
            tokens = br.readLine().split(" ");
            int l = Integer.parseInt(tokens[0]);
            int r = Integer.parseInt(tokens[1]);
            sb.append(query(l, r)).append('\n');
        }
    }

    public static int query(int l, int r) {
        if ((sum[r] - sum[l - 1]) % 3 != 0 || (r - l + 1) % 3 != 0)
            return -1;
        int ret = (r - l + 1) / 3;
        if (match[r - 1] - match[l - 1] == 0)
            ++ret;
        return ret;
    }
}
