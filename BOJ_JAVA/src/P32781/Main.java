package P32781;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final long MOD = 1_000_000_007L;

    static int N;
    static long total;
    static Map<Character, Long> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for (char c : br.readLine().toCharArray())
            map.put(c, map.getOrDefault(c, 0L) + 1L);
        for (char key : map.keySet()) {
            total += combination(map.get(key));
            total %= MOD;
        }
        for (char c1 = 'A'; c1 <= 'z'; ++c1)
            for (char c2 = (char) (c1 + 1); c2 <= 'z'; ++c2)
                if (map.containsKey(c1) && map.containsKey(c2)) {
                    total += (map.get(c1) * map.get(c2)) % MOD;
                    total %= MOD;
                }
        System.out.print(total);
    }

    public static long combination(long n) {
        long ret = 1;
        for (long i = 0; i < n; ++i) {
            ret <<= 1;
            ret %= MOD;
        }
        ret -= n + 1;
        if (ret < 0)
            ret += MOD;
        return ret;
    }
}
