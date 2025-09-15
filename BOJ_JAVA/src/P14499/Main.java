package P14499;

import java.io.*;
import java.util.*;

class Main {

    static class Dice {
        static int[][] rotation = new int[][]{
                { 0, 0, 0, 0 },
                { 5, 3, 2, 4 },
                { 1, 3, 6, 4 },
                { 5, 6, 2, 1 },
                { 5, 1, 2, 6 },
                { 6, 3, 1, 4 },
                { 2, 3, 5, 4 }
        };

        static int[] direction = new int[]{
                NORTH, WEST, SOUTH, EAST
        };

        static int[] written = new int[7];

        int id;
        int[] next = new int[5];

        public Dice(int prev, int curr, int dir) {
            id = curr;

            int i = 0;
            while (rotation[id][i] != prev)
                i++;

            if (dir == EAST || dir == WEST)
                dir = 3 - dir;
            else
                dir = 7 - dir;
            int d = 0;
            while (direction[d] != dir)
                d++;

            for (int j = 0; j < 4; j++)
                next[direction[(d + j) % 4]] = rotation[id][(i + j) % 4];
        }

        public Dice() {
            this(2, 1, NORTH);
        }

        public int getId() {
            return id;
        }

        public int getNextId(int dir) {
            return next[dir];
        }

        public int getBottom() {
            return written[7 - id];
        }

        public void setBottom(int number) {
            written[7 - id] = number;
        }

        public int getTop() {
            return written[id];
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int UNABLE = -1;
    static final int EAST = 1;
    static final int WEST = 2;
    static final int NORTH = 3;
    static final int SOUTH = 4;

    static int N, M, sr, sc, K;
    static int[][] map;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        sr = Integer.parseInt(st.nextToken());
        sc = Integer.parseInt(st.nextToken());
        sr++; sc++;
        K = Integer.parseInt(st.nextToken());

        map = new int[N + 2][M + 2];
        for (int r = 0; r <= N + 1; r++)
            map[r][0] = map[r][M + 1] = UNABLE;
        for (int c = 0; c <= M + 1; c++)
            map[0][c] = map[N + 1][c] = UNABLE;

        for (int r = 1; r <= N; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 1; c <= M; c++)
                map[r][c] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        Dice dice = new Dice();
        while (K-- > 0) {
            int command = Integer.parseInt(st.nextToken());
            if (!isValidCommand(sr, sc, command))
                continue;

            switch (command) {
                case WEST:
                    sc--;
                    break;
                case EAST:
                    sc++;
                    break;
                case NORTH:
                    sr--;
                    break;
                case SOUTH:
                    sr++;
                    break;
            }

            int id = dice.getId();
            int nextId = dice.getNextId(command);
            if (map[sr][sc] > 0) {
                dice = new Dice(id, nextId, command);
                dice.setBottom(map[sr][sc]);
                map[sr][sc] = 0;
            } else {
                dice = new Dice(id, nextId, command);
                map[sr][sc] = dice.getBottom();
            }

            sb.append(dice.getTop()).append('\n');
        }

        System.out.println(sb);
    }

    public static boolean isValidCommand(int r, int c, int dir) {
        switch (dir) {
            case WEST:
                return isValidPoint(r, c - 1);
            case EAST:
                return isValidPoint(r, c + 1);
            case NORTH:
                return isValidPoint(r - 1, c);
            case SOUTH:
                return isValidPoint(r + 1, c);
        }
        return false;
    }

    public static boolean isValidPoint(int r, int c) {
        return map[r][c] != UNABLE;
    }
}