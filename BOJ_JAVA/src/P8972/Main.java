package P8972;

import java.io.*;
import java.util.*;

public class Main {

    static class Unit {
        int r, c;
        boolean destroyed;

        static final int[] dr = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
        static final int[] dc = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

        public Unit(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int getDistance(int tr, int tc) {
            return Math.abs(r - tr) + Math.abs(c - tc);
        }

        public void move(int dir) {
            r = r + dr[dir];
            c = c + dc[dir];
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final char PLAYER = 'I';
    static final char ENEMY = 'R';
    static final int INF = 100_000_000;

    static int R, C;
    static Set<Unit>[][] status;
    static Unit player;
    static List<Unit> enemies = new ArrayList<>();
    static char[] command;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        R = Integer.parseInt(tokens[0]);
        C = Integer.parseInt(tokens[1]);

        status = new Set[R][C];
        for (int r = 0; r < R; ++r) {
            char[] line = br.readLine().toCharArray();
            for (int c = 0; c < C; ++c) {
                status[r][c] = new HashSet<>();
                if (line[c] == PLAYER) {
                    player = new Unit(r, c);
                    status[r][c].add(player);
                } else if (line[c] == ENEMY) {
                    enemies.add(new Unit(r, c));
                    status[r][c].add(enemies.get(enemies.size() - 1));
                }
            }
        }

        command = br.readLine().toCharArray();
    }

    private static void solve() throws IOException {
        for (int turn = 1; turn <= command.length; ++turn) {
            int direction = command[turn - 1] - '0';
            status[player.r][player.c].remove(player);
            player.move(direction);
            status[player.r][player.c].add(player);

            if (status[player.r][player.c].size() > 1) {
                sb.append("kraj ").append(turn);
                return;
            }

            for (Unit enemy : enemies) {
                if (enemy.destroyed)
                    continue;

                int minDir = 0, minDist = INF;
                for (direction = 1; direction <= 9; ++direction) {
                    int r = enemy.r + Unit.dr[direction], c = enemy.c + Unit.dc[direction];
                    if (!isValidPoint(r, c))
                        continue;
                    int dist = player.getDistance(r, c);
                    if (dist < minDist) {
                        minDist = dist;
                        minDir = direction;
                    }
                }

                status[enemy.r][enemy.c].remove(enemy);
                enemy.move(minDir);
                if (enemy.r == player.r && enemy.c == player.c) {
                    sb.append("kraj ").append(turn);
                    return;
                }
                status[enemy.r][enemy.c].add(enemy);
            }

            for (int r = 0; r < R; ++r)
                for (int c = 0; c < C; ++c)
                    if (status[r][c].size() > 1) {
                        for (Unit unit : status[r][c])
                            unit.destroyed = true;
                        status[r][c].clear();
                    }
        }

        char[][] table = new char[R][C];
        for (char[] line : table)
            Arrays.fill(line, '.');
        table[player.r][player.c] = PLAYER;
        for (Unit enemy : enemies)
            if (!enemy.destroyed)
                table[enemy.r][enemy.c] = ENEMY;

        for (char[] line : table)
            sb.append(line).append('\n');
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }
}
