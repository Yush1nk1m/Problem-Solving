package P20414;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, s, g, p, d;
    static char[] array;
    static int[] amount;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        amount = new int[N + 1];

        tokens = br.readLine().split(" ");
        s = Integer.parseInt(tokens[0]);
        g = Integer.parseInt(tokens[1]);
        p = Integer.parseInt(tokens[2]);
        d = Integer.parseInt(tokens[3]);

        array = br.readLine().toCharArray();
        for (int i = 0; i < N; ++i)
            switch (array[i]) {
                case 'B':
                    amount[i] = s - 1;
                    break;
                case 'S':
                    amount[i] = g - 1;
                    break;
                case 'G':
                    amount[i] = p - 1;
                    break;
                case 'P':
                    amount[i] = d - 1;
                    break;
                case 'D':
                    amount[i] = d << 1;
                    break;
            }
        amount[N] = d << 1;
    }

    private static void solve() {
        int prev = 0, sum = 0;
        for (int i = 0; i < N; ++i) {
            int curr = Math.min(d, Math.min(amount[i] - prev, amount[i + 1]));
            sum += curr;
            prev = curr;
        }
        System.out.print(sum);
    }
}
