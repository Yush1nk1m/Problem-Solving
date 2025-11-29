package P1943;

import java.io.*;

public class Main_BottomUp {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, total;
    static int[] coin, count, table, nextState;

    public static void main(String[] args) throws IOException {
        for (int t = 0; t < 3; ++t) {
            N = Integer.parseInt(br.readLine());
            coin = new int[N];
            count = new int[N];
            total = 0;
            for (int i = 0; i < N; ++i) {
                tokens = br.readLine().split(" ");
                coin[i] = Integer.parseInt(tokens[0]);
                count[i] = Integer.parseInt(tokens[1]);
                total += coin[i] * count[i];
            }

            if (total % 2 == 1) {
                sb.append("0\n");
                continue;
            }

            table = new int[total + 1];
            nextState = new int[total + 1];
            table[0] = 1;
            sb.append(solve()).append('\n');
        }
        System.out.println(sb);
    }

    public static int solve() {
        System.arraycopy(table, 0, nextState, 0, table.length);
        for (int i = 0; i < N; ++i) {
            for (int prev = 0; prev < total >> 1; ++prev)
                if (table[prev] == 1)
                    for (int c = 1; c <= count[i]; ++c)
                        nextState[prev + c * coin[i]] = 1;
            System.arraycopy(nextState, 0, table, 0, nextState.length);

            if (table[total >> 1] == 1)
                return 1;
        }
        return 0;
    }
}

