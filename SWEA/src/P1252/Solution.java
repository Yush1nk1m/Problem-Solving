package P1252;

import java.io.*;
import java.util.*;

public class Solution {

    static class Kernel {
        int r, c, size;

        public Kernel(int r, int c, int size) {
            this.r = r;
            this.c = c;
            this.size = size;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int PLAIN = 0;
    static final int CRACKED = 1;

    static int T, S, N;
    static int[][] table;
    static List<Kernel> kernels = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        S = Integer.parseInt(br.readLine());
        N = Integer.parseInt(br.readLine());
        table = new int[S + 1][S + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) {
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            table[r][c] = CRACKED;
        }
        kernels.clear();
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');

        applyKernel(3, 5, 9);
        applyKernel(2, 2, 4);
        applyKernel(1, 1, 1);

        sb.append(kernels.size());
        for (Kernel kernel : kernels)
            sb.append(' ').append(kernel.r).append(' ').append(kernel.c).append(' ').append(kernel.size);
        sb.append('\n');
    }

    private static void applyKernel(int size, int lb, int ub) {
        for (int count = ub; count >= lb; --count)
            for (int r = 1; r <= S - size + 1; ++r)
                for (int c = 1; c <= S - size + 1; ++c)
                    if (countCracks(r, c, size) == count && removeCracks(r, c, size))
                        kernels.add(new Kernel(r, c, size));
    }

    private static int countCracks(int r, int c, int size) {
        int sum = 0;
        for (int i = r; i < r + size; ++i)
            for (int j = c; j < c + size; ++j)
                sum += table[i][j];
        return sum;
    }

    private static boolean removeCracks(int r, int c, int size) {
        for (int i = r; i < r + size; ++i)
            for (int j = c; j < c + size; ++j)
                table[i][j] = PLAIN;
        return true;
    }
}
