package P1019;

import java.io.*;
import java.util.*;

public class Simulation {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.print("[from] [to] [step] : ");
        int from = sc.nextInt();
        int to = sc.nextInt();
        int step = sc.nextInt();
        simulate(from, to, step);
    }

    public static void simulate(int from, int to, int step) {
        for (int n = from; n <= to ; n += step)
            System.out.println(n + " : " + Arrays.toString(run(n)));
    }

    public static int[] run(int n) {
        int[] count = new int[10];
        for (int i = 1; i <= n; i++)
            for (char c : String.valueOf(i).toCharArray())
                ++count[c - '0'];
        return count;
    }
}
