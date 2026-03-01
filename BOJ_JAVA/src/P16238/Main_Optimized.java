package P16238;

import java.io.*;
import java.util.*;

public class Main_Optimized {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static int[] count;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        count = new int[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            count[i] = Integer.parseInt(tokens[i]);
    }

    private static int solve() {
        Arrays.sort(count);
        int i = N - 1, d = 0, sum = 0;
        while (count[i] - d > 0)
            sum += count[i--] - d++;
        return sum;
    }
}
