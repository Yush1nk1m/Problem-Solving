package P1242;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int[][][][] decoder = new int[4][5][4][5];
    static int T, N, M;
    static List<String> screen = new ArrayList<>();
    static Set<String> validated = new HashSet<>();

    public static void main(String[] args) throws IOException {
        preprocess();
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; ++i) {
            sb.append('#').append(i).append(' ');
            initialize();
            solve();
        }
        System.out.print(sb);
    }

    private static void preprocess() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 5; ++j)
                for (int k = 0; k < 4; ++k)
                    for (int l = 0; l < 5; ++l)
                        decoder[i][j][k][l] = -1;

        decoder[3][2][1][1] = 0;
        decoder[2][2][2][1] = 1;
        decoder[2][1][2][2] = 2;
        decoder[1][4][1][1] = 3;
        decoder[1][1][3][2] = 4;
        decoder[1][2][3][1] = 5;
        decoder[1][1][1][4] = 6;
        decoder[1][3][1][2] = 7;
        decoder[1][2][1][3] = 8;
        decoder[3][1][1][2] = 9;
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        screen.clear();
        for (int i = 0; i < N; ++i) {
            String line = convertToBinary(br.readLine());
            if (!screen.isEmpty() && screen.get(screen.size() - 1).equals(line))
                continue;
            screen.add(line);
        }
        validated.clear();
    }

    private static String convertToBinary(String line) {
        StringBuilder builder = new StringBuilder();

        for (char c : line.toCharArray()) {
            int value = 0;
            if ('0' <= c && c <= '9')
                value = c - '0';
            else if ('a' <= c && c <= 'z')
                value = c - 'a' + 10;
            else if ('A' <= c && c <= 'Z')
                value = c - 'A' + 10;

            int subtracter = 8;
            while (subtracter > 0) {
                if (value >= subtracter) {
                    value -= subtracter;
                    builder.append('1');
                } else {
                    builder.append('0');
                }
                subtracter >>= 1;
            }
        }

        return builder.toString();
    }

    private static void solve() {
        int sum = 0;
        for (int r = 0; r < screen.size(); ++r) {
            int c = screen.get(r).length() - 1;
            while (c >= 56) {
                while (c >= 56 && screen.get(r).charAt(c) != '1')
                    --c;

                int length = findCodeLength(screen.get(r), c);
                if (length == 0) {
                    --c;
                    continue;
                }

                sum += validate(screen.get(r).substring(c - length + 1, c + 1));
                c -= length;
            }
        }

        sb.append(sum).append('\n');
    }

    private static int findCodeLength(String line, int end) {
        int[] count = new int[4];
        int curr = end, prev = end, i = 3;
        while (i >= 0 && curr >= 0) {
            while (curr >= 0 && line.charAt(prev) == line.charAt(curr))
                --curr;
            count[i--] = prev - curr;
            prev = curr;
        }
        if (i >= 0)
            return 0;

        int divisor = GCD(count[0], GCD(count[1], GCD(count[2], count[3])));
        for (i = 0; i < 4; ++i)
            count[i] /= divisor;

        return decoder[count[0]][count[1]][count[2]][count[3]] >= 0 ? (end - curr) << 3 : 0;
    }

    private static int GCD(int a, int b) {
        while (a % b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return b;
    }

    private static int validate(String line) {
        int[] code = new int[8];
        int step = line.length() >> 3, sum = 0;
        for (int i = 0; i < 8; ++i) {
            code[i] = getCode(line, i * step, (i + 1) * step - 1);
            if (code[i] == -1)
                return 0;
        }
        if (validated.contains(Arrays.toString(code)) ||
                ((code[0] + code[2] + code[4] + code[6]) * 3 + (code[1] + code[3] + code[5] + code[7])) % 10 != 0)
            return 0;
        validated.add(Arrays.toString(code));
        for (int val : code)
            sum += val;
        return sum;
    }

    private static int getCode(String line, int start, int end) {
        int[] count = new int[4];
        int prev = start, curr = start, i = 0;
        while (curr <= end && i < 4) {
            while (curr <= end && line.charAt(prev) == line.charAt(curr))
                ++curr;
            count[i++] = curr - prev;
            prev = curr;
        }
        if (i < 4)
            return -1;

        int divisor = GCD(count[0], GCD(count[1], GCD(count[2], count[3])));
        for (i = 0; i < 4; ++i)
            count[i] /= divisor;
        return decoder[count[0]][count[1]][count[2]][count[3]];
    }
}

