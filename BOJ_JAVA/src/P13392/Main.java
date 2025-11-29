package P13392;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int NONE = -1;

    static int N;
    static String src, dest;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        src = br.readLine();
        dest = br.readLine();
        cache = new int[10][N];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
        System.out.println(DFS(0, 0));
    }

    public static int DFS(int rotated, int level) {
        if (level == N)
            return 0;
        else if (cache[rotated][level] != NONE)
            return cache[rotated][level];

        int s = (int) (src.charAt(level) - '0' + rotated) % 10;
        int d = (int) (dest.charAt(level) - '0');
        if (s == d)
            return cache[rotated][level] = DFS(rotated, level + 1);
        return cache[rotated][level] = Math.min((s - d + 10) % 10 + DFS(rotated, level + 1), (d - s + 10) % 10 + DFS((rotated + (d - s + 10) % 10) % 10, level + 1));
    }
}
