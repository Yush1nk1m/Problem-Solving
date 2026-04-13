package P10885;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static int[] cache;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            initialize();
            solve();
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
    }
}
