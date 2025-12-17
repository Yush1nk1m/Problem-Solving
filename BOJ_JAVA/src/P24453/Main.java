package P24453;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, X, Y, gap;
    static int[] error;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        error = new int[M + 2];
        error[M + 1] = N + 1;
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= M; ++i) {
            error[i] = Integer.parseInt(tokens[i - 1]);
            gap = Math.max(gap, error[i] - error[i - 1] - 1);
        }
        tokens = br.readLine().split(" ");
        X = Integer.parseInt(tokens[0]);
        Y = Integer.parseInt(tokens[1]);
        if (gap >= X) {
            System.out.println(M - Y);
            return;
        }
        System.out.println(M - solve());
    }

    public static int solve() {
        int l = Y, h = M, ret = M;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (validate(m) >= X) {
                ret = Math.min(ret, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }

    public static int validate(int size) {
        int g = 0;
        for (int i = 1; i < error.length - size; ++i)
            g = Math.max(g, error[i + size] - error[i - 1] - 1);
        return g;
    }
}
