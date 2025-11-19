package P2011;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final long MOD = 1_000_000;

    static String line;
    static long[] cache;

    public static void main(String[] args) throws IOException {
        line = br.readLine();
        cache = new long[line.length()];
        Arrays.fill(cache, -1);
        System.out.println(DFS(0));
    }

    public static long DFS(int index) {
        if (index >= line.length())
            return 1L;
        else if (line.charAt(index) == '0')
            return 0L;
        else if (cache[index] != -1)
            return cache[index];

        cache[index] = DFS(index + 1) % MOD;
        if (index + 1 < line.length() && 10 * (line.charAt(index) - '0') + (line.charAt(index + 1) - '0') <= 26) {
            cache[index] += DFS(index + 2);
            cache[index] %= MOD;
        }

        return cache[index];
    }
}
