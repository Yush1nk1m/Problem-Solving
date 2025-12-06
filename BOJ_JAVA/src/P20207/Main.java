package P20207;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, S, E, l, r, area;
    static int[] count = new int[367];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            tokens = br.readLine().split(" ");
            S = Integer.parseInt(tokens[0]);
            E = Integer.parseInt(tokens[1]);
            while (S <= E)
                ++count[S++];
        }
        while (l <= 365 && r <= 365) {
            int maxHeight = 0;
            while (count[l] == 0 && l <= 365)
                ++l;
            r = l;
            while (count[r] > 0 && r <= 365) {
                maxHeight = Math.max(maxHeight, count[r]);
                ++r;
            }
            area += (r - l) * maxHeight;
            l = r;
        }
        System.out.println(area);
    }
}
