package P23289;

import java.io.*;
import java.util.*;

public class Main {

    static class Fan {
        int r, c, direction;
        boolean[][] blew;

        public Fan(int r, int c, int direction) {
            this.r = r;
            this.c = c;
            this.direction = direction;
            blew = new boolean[(R << 1) + 1][(C << 1) + 1];
        }

        public boolean checkBlowable(int r, int c, int direction) {
            switch (direction) {
                case UP:
                    return isValidPoint(r - 2, c) && !blew[r - 2][c] && !wall[r - 1][c];
                case UP_AND_RIGHT:
                    return isValidPoint(r - 2, c + 2) && !blew[r - 2][c + 2] && !wall[r - 1][c] && !wall[r - 2][c + 1];
                case RIGHT_AND_UP:
                    return isValidPoint(r - 2, c + 2) && !blew[r - 2][c + 2] && !wall[r][c + 1] && !wall[r - 1][c + 2];
                case RIGHT:
                    return isValidPoint(r, c + 2) && !blew[r][c + 2] && !wall[r][c + 1];
                case RIGHT_AND_DOWN:
                    return isValidPoint(r + 2, c + 2) && !blew[r + 2][c + 2] && !wall[r][c + 1] && !wall[r + 1][c + 2];
                case DOWN_AND_RIGHT:
                    return isValidPoint(r + 2, c + 2) && !blew[r + 2][c + 2] && !wall[r + 1][c] && !wall[r + 2][c + 1];
                case DOWN:
                    return isValidPoint(r + 2, c) && !blew[r + 2][c] && !wall[r + 1][c];
                case DOWN_AND_LEFT:
                    return isValidPoint(r + 2, c - 2) && !blew[r + 2][c - 2] && !wall[r + 1][c] && !wall[r + 2][c - 1];
                case LEFT_AND_DOWN:
                    return isValidPoint(r + 2, c - 2) && !blew[r + 2][c - 2] && !wall[r][c - 1] && !wall[r + 1][c - 2];
                case LEFT:
                    return isValidPoint(r, c - 2) && !blew[r][c - 2] && !wall[r][c - 1];
                case LEFT_AND_UP:
                    return isValidPoint(r - 2, c - 2) && !blew[r - 2][c - 2] && !wall[r][c - 1] && !wall[r - 1][c - 2];
                case UP_AND_LEFT:
                    return isValidPoint(r - 2, c - 2) && !blew[r - 2][c - 2] && !wall[r - 1][c] && !wall[r - 2][c - 1];
            }
            return false;
        }

        private boolean isValidPoint(int r, int c) {
            return 2 <= r && r < blew.length && 2 <= c && c < blew[0].length;
        }

        public void blow() {
            for (boolean[] row : blew)
                Arrays.fill(row, false);

            DFS(r + dr[direction], c + dc[direction], 5);
        }

        private void DFS(int r, int c, int power) {
            if (power == 0)
                return;

            blew[r][c] = true;
            table[r][c] += power;
            switch (direction) {
                case RIGHT:
                    if (checkBlowable(r, c, RIGHT))
                        DFS(r + dr[RIGHT], c + dc[RIGHT], power - 1);
                    if (checkBlowable(r, c, UP_AND_RIGHT))
                        DFS(r + dr[UP_AND_RIGHT], c + dc[UP_AND_RIGHT], power - 1);
                    if (checkBlowable(r, c, DOWN_AND_RIGHT))
                        DFS(r + dr[DOWN_AND_RIGHT], c + dc[DOWN_AND_RIGHT], power - 1);
                    break;
                case LEFT:
                    if (checkBlowable(r, c, LEFT))
                        DFS(r + dr[LEFT], c + dc[LEFT], power - 1);
                    if (checkBlowable(r, c, UP_AND_LEFT))
                        DFS(r + dr[UP_AND_LEFT], c + dc[UP_AND_LEFT], power - 1);
                    if (checkBlowable(r, c, DOWN_AND_LEFT))
                        DFS(r + dr[DOWN_AND_LEFT], c + dc[DOWN_AND_LEFT], power - 1);
                    break;
                case UP:
                    if (checkBlowable(r, c, UP))
                        DFS(r + dr[UP], c + dc[UP], power - 1);
                    if (checkBlowable(r, c, LEFT_AND_UP))
                        DFS(r + dr[LEFT_AND_UP], c + dc[LEFT_AND_UP], power - 1);
                    if (checkBlowable(r, c, RIGHT_AND_UP))
                        DFS(r + dr[RIGHT_AND_UP], c + dc[RIGHT_AND_UP], power - 1);
                    break;
                case DOWN:
                    if (checkBlowable(r, c, DOWN))
                        DFS(r + dr[DOWN], c + dc[DOWN], power - 1);
                    if (checkBlowable(r, c, LEFT_AND_DOWN))
                        DFS(r + dr[LEFT_AND_DOWN], c + dc[LEFT_AND_DOWN], power - 1);
                    if (checkBlowable(r, c, RIGHT_AND_DOWN))
                        DFS(r + dr[RIGHT_AND_DOWN], c + dc[RIGHT_AND_DOWN], power - 1);
                    break;
            }
        }
    }

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int UP = 0;
    static final int UP_AND_RIGHT = 1;
    static final int RIGHT_AND_UP = 2;
    static final int RIGHT = 3;
    static final int RIGHT_AND_DOWN = 4;
    static final int DOWN_AND_RIGHT = 5;
    static final int DOWN = 6;
    static final int DOWN_AND_LEFT = 7;
    static final int LEFT_AND_DOWN = 8;
    static final int LEFT = 9;
    static final int LEFT_AND_UP = 10;
    static final int UP_AND_LEFT = 11;
    static final int[] dr = { -2, -2, -2, 0, 2, 2, 2, 2, 2, 0, -2, -2 };
    static final int[] dc = { 0, 2, 2, 2, 2, 2, 0, -2, -2, -2, -2, -2 };

    static int R, C, K, W, r, c, t;
    static int[][] table;
    static boolean[][] wall;
    static List<Coords> examinations = new ArrayList<>();
    static List<Fan> fans = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        table = new int[(R << 1) + 1][(C << 1) + 1];
        wall = new boolean[(R << 1) + 1][(C << 1) + 1];

        for (int r = 2; r <= (R << 1); r += 2) {
            st = new StringTokenizer(br.readLine());
            for (int c = 2; c <= (C << 1); c += 2) {
                int value = Integer.parseInt(st.nextToken());
                if (value >= 5)
                    examinations.add(new Coords(r, c));
                else if (value >= 1) {
                    int direction;
                    switch (value) {
                        case 1:
                            direction = RIGHT;
                            break;
                        case 2:
                            direction = LEFT;
                            break;
                        case 3:
                            direction = UP;
                            break;
                        case 4:
                            direction = DOWN;
                            break;
                        default:
                            direction = 0;
                            break;
                    }
                    fans.add(new Fan(r, c, direction));
                }
            }
        }

        W = Integer.parseInt(br.readLine());
        while (W-- > 0) {
            st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken()) << 1;
            c = Integer.parseInt(st.nextToken()) << 1;
            t = Integer.parseInt(st.nextToken());
            if (t == 0)
                wall[r - 1][c] = true;
            else
                wall[r][c + 1] = true;
        }
    }

    private static int solve() {
        int chocolate = 0;
        do {
            blowWinds();
            adjustTemperatures();
            adjustOuterTemperatures();
            ++chocolate;
        } while (!examineTemperatures() && chocolate <= 100);

        return chocolate;
    }

    private static void blowWinds() {
        for (Fan fan : fans)
            fan.blow();
    }

    private static void adjustTemperatures() {
        int[][] difference = new int[(R << 1) + 1][(C << 1) + 1];
        for (int r = 2; r <= (R << 1); r += 2)
            for (int c = 2; c <= (C << 1); c += 2) {
                if (c + 2 <= (C << 1) && !wall[r][c + 1]) {
                    difference[r][c] += (table[r][c + 2] - table[r][c]) / 4;
                    difference[r][c + 2] += (table[r][c] - table[r][c + 2]) / 4;
                }
                if (r + 2 <= (R << 1) && !wall[r + 1][c]) {
                    difference[r][c] += (table[r + 2][c] - table[r][c]) / 4;
                    difference[r + 2][c] += (table[r][c] - table[r + 2][c]) / 4;
                }
            }

        for (int r = 2; r <= (R << 1); r += 2)
            for (int c = 2; c <= (C << 1); c += 2)
                table[r][c] += difference[r][c];
    }

    private static void adjustOuterTemperatures() {
        for (int r = 2; r < (R << 1); r += 2)
            table[r][2] = Math.max(0, table[r][2] - 1);
        for (int c = 2; c < (C << 1); c += 2)
            table[R << 1][c] = Math.max(0, table[R << 1][c] - 1);
        for (int r = (R << 1); r > 2; r -= 2)
            table[r][C << 1] = Math.max(0, table[r][C << 1] - 1);
        for (int c = (C << 1); c > 2; c -= 2)
            table[2][c] = Math.max(0, table[2][c] - 1);
    }

    private static boolean examineTemperatures() {
        for (Coords coords : examinations)
            if (table[coords.r][coords.c] < K)
                return false;
        return true;
    }
}
