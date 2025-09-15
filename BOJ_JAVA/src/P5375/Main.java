package P5375;

import java.io.*;
import java.util.*;

public class Main {

    static class Cube {
        static final char[] color = new char[]{'w', 'y', 'r', 'o', 'g', 'b'};
        static final int U = 0, D = 1, F = 2, B = 3, L = 4, R = 5;
        static final int[] dr = new int[]{0, 0, 0, 1, 2, 2, 2, 1}, dc = new int[]{0, 1, 2, 2, 2, 1, 0, 0};

        char[][][] figure = new char[6][3][3];

        public Cube() {
            for (int i = 0; i < 6; i++)
                for (char[] row : figure[i])
                    Arrays.fill(row, color[i]);
        }

        public void rotate(String command) {
            char[][] matrix = null;
            char surface = command.charAt(0);
            char dir = command.charAt(1);

            switch (surface) {
                case 'U': matrix = figure[U]; break;
                case 'D': matrix = figure[D]; break;
                case 'F': matrix = figure[F]; break;
                case 'B': matrix = figure[B]; break;
                case 'L': matrix = figure[L]; break;
                case 'R': matrix = figure[R]; break;
            }

            char[] temp = new char[2];
            if (dir == '+') {
                for (int i = 0; i < 2; i++)
                    temp[i] = matrix[dr[6 + i]][dc[6 + 1]];
                for (int i = 5; i >= 0; i--)
                    matrix[dr[i + 2]][dc[i + 2]] = matrix[dr[i]][dc[i]];
                for (int i = 0; i < 2; i++)
                    matrix[dr[i]][dc[i]] = temp[i];
            } else {
                for (int i = 0; i < 2; i++)
                    temp[i] = matrix[dr[i]][dc[i]];
                for (int i = 2; i < 8; i++)
                    matrix[dr[i - 2]][dc[i - 2]] = matrix[dr[i]][dc[i]];
                for (int i = 0; i < 2; i++)
                    matrix[dr[6 + i]][dc[6 + i]] = temp[i];
            }

            temp = new char[3];
            char[][] s1, s2, s3, s4;
            if (surface == 'U') {
                s1 = figure[F]; s2 = figure[R]; s3 = figure[B]; s4 = figure[L];
                for (int i = 0; i < 3; i++)
                    temp[i] = s1[0][i];
                if (dir == '+')
                    for (int i = 0; i < 3; i++) {
                        s1[0][i] = s2[0][i]; s2[0][i] = s3[0][i]; s3[0][i] = s4[0][i]; s4[0][i] = temp[i];
                    }
                else
                    for (int i = 0; i < 3; i++) {
                        s1[0][i] = s4[0][i]; s4[0][i] = s3[0][i]; s3[0][i] = s2[0][i]; s2[0][i] = temp[i];
                    }
            } else if (surface == 'D') {
                s1 = figure[F]; s2 = figure[L]; s3 = figure[B]; s4 = figure[R];
                for (int i = 0; i < 3; i++)
                    temp[i] = s1[2][i];
                if (dir == '+')
                    for (int i = 0; i < 3; i++) {
                        s1[2][i] = s2[2][i]; s2[2][i] = s3[2][i]; s3[2][i] = s4[2][i]; s4[2][i] = temp[i];
                    }
                else
                    for (int i = 0; i < 3; i++) {
                        s1[2][i] = s4[2][i]; s4[2][i] = s3[2][i]; s3[2][i] = s2[2][i]; s2[2][i] = temp[i];
                    }
            } else if (surface == 'F') {
                s1 = figure[U]; s2 = figure[L]; s3 = figure[D]; s4 = figure[R];
                for (int i = 0; i < 3; i++)
                    temp[i] = s1[2][i];
                if (dir == '+')
                    for (int i = 0; i < 3; i++) {
                        s1[2][i] = s2[2 - i][2]; s2[2 - i][2] = s3[0][2 - i]; s3[0][2 - i] = s4[i][0]; s4[i][0] = temp[i];
                    }
                else
                    for (int i = 0; i < 3; i++) {
                        s1[2][i] = s4[i][0]; s4[i][0] = s3[0][2 - i]; s3[0][2 - i] = s2[2 - i][2]; s2[2 - i][2] = temp[i];
                    }
            } else if (surface == 'B') {
                s1 = figure[U]; s2 = figure[R]; s3 = figure[D]; s4 = figure[L];
                for (int i = 0; i < 3; i++)
                    temp[i] = s1[0][i];
                if (dir == '+')
                    for (int i = 0; i < 3; i++) {
                        s1[0][i] = s2[i][2]; s2[i][2] = s3[2][2 - i]; s3[2][2 - i] = s4[2 - i][0]; s4[2 - i][0] = temp[i];
                    }
                else
                    for (int i = 0; i < 3; i++) {
                        s1[0][i] = s4[2 - i][0]; s4[2 - i][0] = s3[2][2 - i]; s3[2][2 - i] = s2[i][2]; s2[i][2] = temp[i];
                    }
            } else if (surface == 'L') {
                s1 = figure[U]; s2 = figure[B]; s3 = figure[D]; s4 = figure[F];
                for (int i = 0; i < 3; i++)
                    temp[i] = s1[i][0];
                if (dir == '+')
                    for (int i = 0; i < 3; i++) {
                        s1[i][0] = s2[2 - i][2]; s2[2 - i][2] = s3[i][0]; s3[i][0] = s4[i][0]; s4[i][0] = temp[i];
                    }
                else
                    for (int i = 0; i < 3; i++) {
                        s1[i][0] = s4[i][0]; s4[i][0] = s3[i][0]; s3[i][0] = s2[2 - i][2]; s2[2 - i][2] = temp[i];
                    }
            } else if (surface == 'R') {
                s1 = figure[U]; s2 = figure[F]; s3 = figure[D]; s4 = figure[B];
                for (int i = 0; i < 3; i++)
                    temp[i] = s1[i][2];
                if (dir == '+')
                    for (int i = 0; i < 3; i++) {
                        s1[i][2] = s2[i][2]; s2[i][2] = s3[i][2]; s3[i][2] = s4[2 - i][0]; s4[2 - i][0] = temp[i];
                    }
                else
                    for (int i = 0; i < 3; i++) {
                        s1[i][2] = s4[2 - i][0]; s4[2 - i][0] = s3[i][2]; s3[i][2] = s2[i][2]; s2[i][2] = temp[i];
                    }
            }
        }

        public char[][] getUpside() {
            return figure[U];
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int T, N;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            char[][] status = solve();
            for (char[] row : status)
                sb.append(row).append('\n');
        }
        System.out.println(sb);
    }

    public static char[][] solve() throws IOException {
        Cube cube = new Cube();
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        while (N-- > 0)
            cube.rotate(st.nextToken());
        return cube.getUpside();
    }
}
