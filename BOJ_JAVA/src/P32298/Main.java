package P32298;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M;
    static boolean[] sieve = new boolean[2_000_001];

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Arrays.fill(sieve, true);
        sieve[1] = false;
        for (int i = 2; i < 2_000_000; i++)
            if (sieve[i])
                for (int m = i * 2; m <= 2_000_000; m += i)
                    sieve[m] = false;

        Outer: for (int from = 1; from <= 2_000_000; from++) {
                    if (sieve[from])
                        continue;
                    for (int step = 1; step < N; step++) {
                        if (from + step * M > 2_000_000)
                            break Outer;
                        else if (sieve[from + step * M])
                            continue Outer;
                    }
                    sb.append(from).append(' ');
                    for (int step = 1; step < N; step++)
                        sb.append(from + step * M).append(' ');
                    break;
        }

        if (sb.length() == 0)
            System.out.println(-1);
        else
            System.out.println(sb);
    }
}
