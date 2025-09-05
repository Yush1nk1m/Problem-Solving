package P20544;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final long NONE = -1;
    static final long MOD = 1_000_000_007L;

    static int N;
    static long[][][][] cache = new long[3][3][3][1002];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    Arrays.fill(cache[i][j][k], NONE);
        System.out.println(DFS(0, 0, 0, 1));
    }

    public static long DFS(int prev, int curr, int maxHeight, int point) {
        if (prev + curr >= 4)
            return 0;
        else if (point == N)
            return maxHeight >= 2 ? 1 : 0;
        else if (cache[prev][curr][maxHeight][point] != NONE)
            return cache[prev][curr][maxHeight][point];

        cache[prev][curr][maxHeight][point] = 0;
        if (prev == 0 || curr == 0) {
            cache[prev][curr][maxHeight][point] += DFS(curr, 1, Math.max(1, maxHeight), point + 1);
            cache[prev][curr][maxHeight][point] %= MOD;
            cache[prev][curr][maxHeight][point] += DFS(curr, 2, 2, point + 1);
            cache[prev][curr][maxHeight][point] %= MOD;
        }
        cache[prev][curr][maxHeight][point] += DFS(curr, 0, maxHeight, point + 1);
        cache[prev][curr][maxHeight][point] %= MOD;

        return cache[prev][curr][maxHeight][point];
    }
}
