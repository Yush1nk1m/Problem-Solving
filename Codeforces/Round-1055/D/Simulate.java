package D;

import java.io.IOException;
import java.util.*;

public class Simulate {

    static Scanner sc = new Scanner(System.in);

    static int[] turns = new int[100];

    public static void main(String[] args) throws IOException {
        for (int n = 1; n <= 130; n++)
            test(n);

        for (int i = 0; i < 20; i++)
            System.out.println("turns[" + i + "]: " + turns[i]);
    }

    public static void test(int n) {
        int i = n;
        int cnt = 0;
        while (i > 1) {
            ++cnt;
            i /= 2;
            if (i <= 1)
                break;
            ++i;
        }
        System.out.println(n + " calculated turn : " + (int) Math.ceil(Math.log(n - 1) / Math.log(2)));
        System.out.println("(n, turn) : " + "(" + n + ", " + cnt + ")");
        ++turns[cnt];
    }
}
