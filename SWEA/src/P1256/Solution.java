package P1256;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T, K;
    static String word;
    static String[] array;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        K = Integer.parseInt(br.readLine());
        word = br.readLine();
        array = new String[word.length()];
        for (int i = 0; i < array.length; ++i)
            array[i] = word.substring(i);
        Arrays.sort(array);
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ').append(array[K - 1]).append('\n');
    }
}
