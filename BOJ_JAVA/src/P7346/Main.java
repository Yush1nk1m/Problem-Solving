package P7346;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int[][] table = new int[][]{
            {5, -1, -2, -1, -3},
            {-1, 5, -3, -2, -4},
            {-2, -3, 5, -2, -2},
            {-1, -2, -2, 5, -1},
            {-3, -4, -2, -1, 0}
    };
    static final int NONE = -1;

    static int T, L1, L2;
    static char[] line1, line2;
    static int[][] cache = new int[100][100];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            tokens = br.readLine().split(" ");
            L1 = Integer.parseInt(tokens[0]);
            line1 = tokens[1].toCharArray();
            tokens = br.readLine().split(" ");
            L2 = Integer.parseInt(tokens[0]);
            line2 = tokens[1].toCharArray();
            for (int[] row : cache)
                Arrays.fill(row, NONE);
            sb.append(DFS(0, 0)).append('\n');
        }
        System.out.println(sb);
    }

    public static int DFS(int l1, int l2) {
        if (l1 == L1 || l2 == L2) {
            int ret = 0;
            while (l1 != L1)
                ret += table[getTableIndex(line1[l1++])][4];
            while (l2 != L2)
                ret += table[getTableIndex(line2[l2++])][4];
            return ret;
        } else if (cache[l1][l2] != NONE)
            return cache[l1][l2];

        int i1 = getTableIndex(line1[l1]), i2 = getTableIndex(line2[l2]);
        return cache[l1][l2] = Math.max(table[i1][i2] + DFS(l1 + 1, l2 + 1), Math.max(table[i1][4] + DFS(l1 + 1, l2), table[i2][4] + DFS(l1, l2 + 1)));
    }

    public static int getTableIndex(char c) {
        switch (c) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
            default:
                return 4;
        }
    }
}
