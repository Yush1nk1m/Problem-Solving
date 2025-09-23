package P1790;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, k, digit = 1, count = 9, target;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        --k;
        while (N - count > 0 && k - digit * count >= 0) {
            N -= count;
            target += count;
            k -= digit * count;
            ++digit;
            count *= 10;
        }
        if (N > 0) {
            N -= k / digit + 1;
            target += k / digit + 1;
            k %= digit;
        }

        if (N < 0)
            System.out.println(-1);
        else
            System.out.println(String.valueOf(target).charAt(k));
    }
}
