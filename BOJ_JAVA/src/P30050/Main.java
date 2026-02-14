package P30050;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int Q, q;
    static long a, b;
    static Map<Long, Long> parent = new HashMap<>();

    public static void main(String[] args) throws IOException {
        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            tokens = br.readLine().split(" ");
            q = Integer.parseInt(tokens[0]);
            a = Long.parseLong(tokens[1]);
            b = Long.parseLong(tokens[2]);
            if (q == 1)
                parent.put(b, a);
            else
                sb.append(getDistance(a, b)).append('\n');
        }
        System.out.print(sb);
    }

    public static long getDistance(long a, long b) {
        long total = 0;
        while (a != b) {
            if (a < b) {
                total += b;
                b = parent.getOrDefault(b, b >> 1);
            } else {
                total += a;
                a = parent.getOrDefault(a, a >> 1);
            }
        }
        total += a;

        return total;
    }
}
