package P27970;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final long MOD = 1_000_000_007L;
    static long base = 1;
    static long op = 0;

    public static void main(String[] args) throws IOException {
        for (char c : br.readLine().toCharArray()) {
            if (c == 'O') {
                op += base;
                op %= MOD;
            }
            base *= 2;
            base %= MOD;
        }
        System.out.println(op);
    }
}
