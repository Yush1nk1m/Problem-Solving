package P28449;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M;
    static long win, lose, draw;
    static int[] a, b;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        a = new int[N];
        b = new int[M];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            a[i] = Integer.parseInt(tokens[i]);
        tokens = br.readLine().split(" ");
        for (int i = 0; i < M; ++i)
            b[i] = Integer.parseInt(tokens[i]);
        Arrays.sort(a);
        Arrays.sort(b);
        for (int key : a) {
            long w = binarySearch(b, key - 1) + 1;
            long l = b.length - binarySearch(b, key) - 1;
            long d = b.length - (w + l);
            win += w;
            lose += l;
            draw += d;
        }
        System.out.println(win + " " + lose + " " + draw);
    }

    public static int binarySearch(int[] array, int key) {
        int l = 0, h = array.length - 1, index = -1;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (array[m] <= key) {
                index = Math.max(index, m);
                l = m + 1;
            } else if (array[m] > key) {
                h = m - 1;
            }
        }
        return index;
    }
}
