package P13701;

import java.io.*;
import java.util.*;

public class Main {

    private static Integer n;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        Bitmask mask = new Bitmask();

        while (st.hasMoreTokens()) {
            n = Integer.parseInt(st.nextToken());
            if (!mask.get(n)) {
                mask.set(n);
                bw.write(n.toString() + " ");
            }
        }
        bw.flush();
        bw.close();
    }

    static class Bitmask {
        private int[] mask;

        public Bitmask() {
            mask = new int[1 << 20];
        }

        public boolean get(int number) {
            return (mask[number / 32] & (1 << (number % 32))) != 0;
        }

        public void set(int number) {
            mask[number / 32] |= (1 << (number % 32));
        }
    }
}
