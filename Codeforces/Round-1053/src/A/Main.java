package A;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, n, m;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0)
            sb.append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int prev = 0;
        while (m-- > 0) {
            int curr = Integer.parseInt(st.nextToken());
            if (curr <= prev)
                return 1;
            prev = curr;
        }

        return n - prev + 1;
    }
}
