package P30463;

import java.io.*;
import java.util.*;

class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st;

    public static int N, K;
    public static long result;
    public static long[] count = new long[1 << 10];

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        while (N-- > 0)
            ++count[getMask(br.readLine())];
        for (int m1 = 1; m1 < (1 << 10); m1++)
            for (int m2 = 1; m2 <= m1; m2++)
                if (countBit(m1 | m2) == K)
                    result += m1 == m2
                            ? count[m1] * (count[m2] - 1) / 2
                            : count[m1] * count[m2];
        System.out.println(result);
    }

    public static int getMask(String line) {
        int mask = 0;
        for (char c : line.toCharArray())
            mask |= 1 << (c - '0');
        return mask;
    }

    public static int countBit(int mask) {
        int c = 0;
        for (int i = 0; i < 10; i++)
            if ((mask & (1 << i)) != 0)
                c++;
        return c;
    }
}
