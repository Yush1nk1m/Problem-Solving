package P1943;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static int N, total;
    static int[] coin, count;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 3; ++i) {
            N = Integer.parseInt(br.readLine());
            coin = new int[N];
            count = new int[N];
            total = 0;
            for (int j = 0; j < N; ++j) {
                tokens = br.readLine().split(" ");
                coin[j] = Integer.parseInt(tokens[0]);
                count[j] = Integer.parseInt(tokens[1]);
                total += coin[j] * count[j];
            }

            if (total % 2 == 1) {
                sb.append(0).append('\n');
                continue;
            }

            cache = new int[N][(total >> 1) + 1];
            for (int[] row : cache)
                Arrays.fill(row, NONE);

            sb.append(DFS(0, total >> 1)).append('\n');
        }
        System.out.println(sb);
    }

    public static int DFS(int index, int amount) {
        if (amount == 0)
            return 1;
        else if (amount < 0 || index == N)
            return 0;
        else if (cache[index][amount] != NONE)
            return cache[index][amount];

        for (int c = count[index]; c >= 0; --c)
            cache[index][amount] = Math.max(cache[index][amount], DFS(index + 1, amount - c * coin[index]));

        return cache[index][amount];
    }
}
