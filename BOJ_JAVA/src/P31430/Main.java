package P31430;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int T;
    static long A, B;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        if (T == 1) {
            tokens = br.readLine().split(" ");
            A = Long.parseLong(tokens[0]);
            B = Long.parseLong(tokens[1]);
            System.out.print(encode(A + B));
        } else {
            System.out.print(decode(br.readLine().toCharArray()));
        }
    }

    public static char[] encode(long number) {
        char[] line = new char[13];
        int i = 13;
        while (--i >= 0) {
            line[i] = (char) ('a' + (char) (number % 26));
            number /= 26;
        }
        return line;
    }

    public static long decode(char[] array) {
        long number = 0;
        int i = -1;
        while (++i < 13) {
            number *= 26;
            number += (array[i] - 'a');
        }
        return number;
    }
}
