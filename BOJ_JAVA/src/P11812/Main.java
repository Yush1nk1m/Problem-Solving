package P11812;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static long N, K, Q, x, y;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Long.parseLong(tokens[0]);
        K = Long.parseLong(tokens[1]);
        Q = Long.parseLong(tokens[2]);
        while (Q-- > 0) {
            tokens = br.readLine().split(" ");
            x = Long.parseLong(tokens[0]);
            y = Long.parseLong(tokens[1]);
            sb.append(solve(x, y)).append('\n');
        }
        System.out.print(sb);
    }

    public static long solve(long x, long y) {
        if (K == 1)
            return Math.abs(x - y);

        long count = 0;

        while (x != y) {
            ++count;
            if (x > y)
                x = (x + K - 2) / K;
            else
                y = (y + K - 2) / K;
        }

        return count;
    }
}
