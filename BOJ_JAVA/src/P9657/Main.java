package P9657;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static int[][][] cache = new int[1001][3][5];
    private static final int NONE = 0;
    private static final int SK = 1;
    private static final int CY = 2;

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        int result = search(N, SK);
        if (result == SK) {
            bw.write("SK");
        } else {
            bw.write("CY");
        }
        bw.flush();
        bw.close();
    }

    static int search(int rock, int turn) {
        if (rock == 0) {
            return (turn == SK) ? CY : SK;
        }

        int next = (turn == SK) ? CY : SK;
        for (int i : Arrays.asList(1, 3, 4)) {
            if (cache[rock][turn][i] == NONE && rock >= i) {
                cache[rock][turn][i] = search(rock - i, next);
            }
        }

        for (int i : Arrays.asList(1, 3, 4)) {
            if (cache[rock][turn][i] == turn) {
                return turn;
            }
        }
        return next;
    }
}
