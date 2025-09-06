package P1437;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final long MOD = 10_007L;
    static long N;

    public static void main(String[] args) throws IOException {
        N = Long.parseLong(br.readLine());
        long sol = 1;
        while (4 < N) {
            N -= 3;
            sol *= 3;
            sol %= MOD;
        }
        sol *= N;
        sol %= MOD;
        System.out.println(sol);
    }

}
