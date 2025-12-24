package P20061;

import java.io.*;

public class Main {

    static class Board {
        int status[] = new int[6];

        public void place(int y, int x) {
            status[y] |= (1 << x);
        }

        public int getMaxDepth(int x) {
            int y = 0;
            while (y < 6 && (status[y] & (1 << x)) == 0)
                ++y;
            return y - 1;
        }

        public int scoring() {
            int score = 0;
            for (int y = 0; y < 6; ++y)
                if (status[y] == 15) {
                    ++score;
                    status[y] = 0;
                }
            coalesce();

            int collapse = Math.min(1, status[0]) + Math.min(1, status[1]);
            for (int y = 5; y > 5 - collapse; --y)
                status[y] = 0;
            coalesce();

            return score;
        }

        public void coalesce() {
            int y1 = 5, y2 = 5, tmp;
            while (y1 >= 0 && y2 >= 0) {
                if (status[y1] != 0) {
                    tmp = status[y1];
                    status[y1--] = 0;
                    status[y2--] = tmp;
                } else {
                    --y1;
                }
            }
        }

        public int countCell() {
            int count = 0;
            for (int y = 0; y < 6; ++y)
                for (int x = 0; x < 4; ++x)
                    if ((status[y] & (1 << x)) != 0)
                        ++count;
            return count;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, t, x, y, d, score;
    static Board green = new Board(), blue = new Board();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            tokens = br.readLine().split(" ");
            t = Integer.parseInt(tokens[0]);
            x = Integer.parseInt(tokens[1]);
            y = Integer.parseInt(tokens[2]);

            if (t == 1) {
                d = green.getMaxDepth(x);
                green.place(d, x);
                score += green.scoring();

                d = blue.getMaxDepth(y);
                blue.place(d, y);
                score += blue.scoring();
            } else if (t == 2) {
                d = green.getMaxDepth(x);
                green.place(d, x);
                green.place(d - 1, x);
                score += green.scoring();

                d = Math.min(blue.getMaxDepth(y), blue.getMaxDepth(y + 1));
                blue.place(d, y);
                blue.place(d, y + 1);
                score += blue.scoring();
            } else {
                d = Math.min(green.getMaxDepth(x), green.getMaxDepth(x + 1));
                green.place(d, x);
                green.place(d, x + 1);
                score += green.scoring();

                d = blue.getMaxDepth(y);
                blue.place(d, y);
                blue.place(d - 1, y);
                score += blue.scoring();
            }
        }
        System.out.println(score);
        System.out.println(green.countCell() + blue.countCell());
    }
}
