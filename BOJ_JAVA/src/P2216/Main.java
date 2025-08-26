package P2216;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int A, B, C;
    static String s1, s2;
    static final char EMPTY = ' ';
    static final int MAX = 1000000000;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        s1 = br.readLine();
        s2 = br.readLine();
        cache = new int[s1.length() + 1][s2.length() + 1];
        for (int[] row : cache)
            Arrays.fill(row, -MAX);
        bw.write(String.valueOf(dfs(0, 0)));
        bw.close();
        br.close();
    }

    public static int dfs(int i1, int i2) {
        if (i1 == s1.length()) {
            int ret = 0;
            while (i2 < s2.length())
                ret += calculateScore(EMPTY, s2.charAt(i2++));
            return ret;
        } else if (i2 == s2.length()) {
            int ret = 0;
            while (i1 < s1.length())
                ret += calculateScore(s1.charAt(i1++), EMPTY);
            return ret;
        } else if (cache[i1][i2] != -MAX)
            return cache[i1][i2];

        cache[i1][i2] = Math.max(
                dfs(i1 + 1, i2) + calculateScore(s1.charAt(i1), EMPTY),
                dfs(i1, i2 + 1) + calculateScore(EMPTY, s2.charAt(i2))
        );
        cache[i1][i2] = Math.max(cache[i1][i2], dfs(i1 + 1, i2 + 1) + calculateScore(s1.charAt(i1), s2.charAt(i2)));

        return cache[i1][i2];
    }

    public static int calculateScore(char c1, char c2) {
        if (c1 == ' ' || c2 == ' ')
            return B;
        else if (c1 == c2)
            return A;
        else
            return C;
    }
}
