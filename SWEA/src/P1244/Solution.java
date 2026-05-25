package P1244;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static int t, bound;
    static int[] array;
    static int[][] cache = new int[1000000][11];

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int x = 1; x <= t; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        String line = st.nextToken();
        array = new int[line.length()];
        for (int i = 0; i < array.length; ++i)
            array[i] = line.charAt(i) - '0';
        bound = Integer.parseInt(st.nextToken());
        for (int[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ').append(DFS(sum(array), bound)).append('\n');
    }

    private static int DFS(int curr, int count) {
        if (count == 0)
            return cache[curr][count] = curr;
        else if (cache[curr][count] != NONE)
            return cache[curr][count];

        cache[curr][count] = 0;
        for (int i = 0; i < array.length - 1; ++i)
            for (int j = i + 1; j < array.length; ++j) {
                swap(array, i, j);
                cache[curr][count] = Math.max(cache[curr][count], DFS(sum(array), count - 1));
                swap(array, i, j);
            }
        return cache[curr][count];
    }

    private static int sum(int[] array) {
        int ret = 0;
        for (int number : array)
            ret = ret * 10 + number;
        return ret;
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
