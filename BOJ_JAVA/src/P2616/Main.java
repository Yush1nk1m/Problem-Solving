package P2616;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;

    static int n, size;
    static int[] people;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        people = new int[n + 1];
        cache = new int[3][n + 1];
        for (int[] row : cache)
            Arrays.fill(row, NONE);

        tokens = br.readLine().split(" ");
        for (int i = 1; i <= n; ++i) {
            people[i] = Integer.parseInt(tokens[i - 1]);
            people[i] += people[i - 1];
        }

        size = Integer.parseInt(br.readLine());
    }

    private static void solve() {
        System.out.print(DFS(0, size));
    }

    private static int DFS(int count, int index) {
        if (index > n || count >= 3)
            return 0;
        else if (cache[count][index] != NONE)
            return cache[count][index];

        return cache[count][index] = Math.max(
                (people[index] - people[index - size]) + DFS(count + 1, index + size),
                DFS(count, index + 1)
        );
    }
}
