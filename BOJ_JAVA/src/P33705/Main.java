package P33705;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, result = 2;
    static int[] sum;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        sum = new int[N + 1];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i) {
            sum[i + 1] = tokens[i].equals("1") ? 1 : 0;
            sum[i + 1] += sum[i];
        }

        if (electable(sum[N] - sum[0], N))
            result = 0;
        if (result == 2)
            for (int i = 0; i < N; i++)
                if (electable(sum[N] - sum[i], N - i) ||
                        electable(sum[N - i] - sum[0], N - i)) {
                    result = 1;
                    break;
                }
        System.out.print(result);
    }

    public static boolean electable(int voter, int total) {
        return voter >= (total + 1) >> 1;
    }
}
