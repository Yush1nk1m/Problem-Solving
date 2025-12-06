package P31091;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] liar;
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        liar = new int[N + 2];
        tokens = br.readLine().split(" ");
        for (String token : tokens) {
            int l = Integer.parseInt(token);
            if (l <= 0) {
                ++liar[0];
                --liar[-l + 1];
            } else {
                ++liar[l];
            }
        }
        for (int i = 1; i < liar.length; ++i)
            liar[i] += liar[i - 1];

        for (int i = 0; i <= N; ++i)
            if (liar[i] == N - i)
                list.add(i);

        sb.append(list.size()).append('\n');
        for (int l : list)
            sb.append(l).append(' ');
        System.out.println(sb);
    }
}
