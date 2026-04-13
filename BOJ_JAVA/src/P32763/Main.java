package P32763;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static boolean[] same;
    static char sign = 0;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        same = new boolean[N + 1];
    }

    private static void solve() throws IOException {
        for (int i = 2; i <= N; ++i) {
            bw.write("? 1 * " + i + "\n");
            bw.flush();
            char c = br.readLine().charAt(0);
            if (c == '+') {
                same[i] = true;
                if (sign == 0) {
                    bw.write("? 1 + " + i + "\n");
                    bw.flush();
                    sign = br.readLine().charAt(0);
                }
            }
        }
        if (sign == 0) {
            bw.write("? 2 + 3\n");
            bw.flush();
            sign = br.readLine().charAt(0) == '+' ? '-' : '+';
        }

        bw.write("! " + sign + " ");
        for (int i = 2; i <= N; ++i) {
            bw.write(same[i] ? sign : sign == '+' ? '-' : '+');
            bw.write(" ");
        }
        bw.flush();
    }
}
