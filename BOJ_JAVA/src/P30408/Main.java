package P30408;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static long N, M;
    static Map<Long, Boolean> cache = new HashMap<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Long.parseLong(tokens[0]);
        M = Long.parseLong(tokens[1]);
        if (DFS(N, M))
            System.out.print("YES");
        else
            System.out.print("NO");
    }

    public static boolean DFS(long curr, long target) {
        if (curr == target)
            return true;
        else if (curr < target)
            return false;
        else if (cache.containsKey(curr))
            return cache.get(curr);

        cache.put(curr,
                curr % 2 == 0
                        ? DFS(curr >> 1, target)
                        : DFS((curr - 1) >> 1, target) | DFS(((curr - 1) >> 1) + 1, target)
        );
        return cache.get(curr);
    }
}
