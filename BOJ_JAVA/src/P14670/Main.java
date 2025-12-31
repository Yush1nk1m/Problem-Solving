package P14670;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static String[] tokens;

    static final int NONE = -1;

    static int N, R, symptom, name;
    static int[] map = new int[101];

    public static void main(String[] args) throws IOException {
        Arrays.fill(map, NONE);
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            tokens = br.readLine().split(" ");
            symptom = Integer.parseInt(tokens[0]);
            name = Integer.parseInt(tokens[1]);
            map[symptom] = name;
        }
        R = Integer.parseInt(br.readLine());
        Outer: while (R-- > 0) {
            tokens = br.readLine().split(" ");
            StringBuilder lineSb = new StringBuilder();
            for (int i = 1; i < tokens.length; ++i) {
                int symptom = Integer.parseInt(tokens[i]);
                if (map[symptom] == NONE) {
                    sb.append("YOU DIED\n");
                    continue Outer;
                }
                lineSb.append(map[symptom]).append(' ');
            }
            sb.append(lineSb).append('\n');
        }
        System.out.print(sb);
    }
}
