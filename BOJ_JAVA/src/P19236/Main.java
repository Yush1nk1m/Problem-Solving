package P19236;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords {
        int row, column;

        public Coords(int row, int column) {
            this.row = row;
            this.column = column;
        }

        public boolean isValidRange() {
            return 0 <= row && row < 4 && 0 <= column && column < 4;
        }
    }

    static class Unit {
        int id, direction, row, column;

        public Unit(int id, int direction, int row, int column) {
            this.id = id;
            this.direction = direction;
            this.row = row;
            this.column = column;
        }

        public Coords nextCoords() {
            return new Coords(row + dr[direction], column + dc[direction]);
        }

        public Unit copy() {
            return new Unit(this.id, this.direction, this.row, this.column);
        }
    }

    static class Status {
        int score;
        Unit[] units;
        Unit[][] table;

        public Status(int score, Unit[] units, Unit[][] table) {
            this.score = score;
            this.units = units;
            this.table = table;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dc = {0, -1, -1, -1, 0, 1, 1, 1};

    static int a, b;
    static Unit[] units = new Unit[17];
    static Unit[][] table = new Unit[4][4];

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        units[0] = new Unit(0, 0, 0, 0);
        for (int r = 0; r < 4; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < 4; ++c) {
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                units[a] = new Unit(a, b - 1, r, c);
                table[r][c] = units[a];
            }
        }
    }

    private static void solve() {
        System.out.print(BFS());
    }

    private static int BFS() {
        Queue<Status> queue = new LinkedList<>();
        int score = table[0][0].id, maxScore = 0;
        units[0].direction = table[0][0].direction;
        units[table[0][0].id] = null;
        table[0][0] = units[0];

        queue.offer(new Status(score, units, table));
        while (!queue.isEmpty()) {
            Status status = queue.poll();
            Unit[] units = status.units;
            Unit[][] table = status.table;
            maxScore = Math.max(maxScore, status.score);

            for (int i = 1; i <= 16; ++i)
                if (units[i] != null) {
                    Coords coords = units[i].nextCoords();
                    while (!coords.isValidRange() || table[coords.row][coords.column] == units[0]) {
                        units[i].direction = (units[i].direction + 1) % 8;
                        coords = units[i].nextCoords();
                    }

                    int temp;
                    Unit opponent = table[coords.row][coords.column];
                    if (opponent != null) {
                        temp = units[i].row; units[i].row = opponent.row; opponent.row = temp;
                        temp = units[i].column; units[i].column = opponent.column; opponent.column = temp;
                        table[units[i].row][units[i].column] = units[i];
                        table[opponent.row][opponent.column] = opponent;
                    } else {
                        table[units[i].row][units[i].column] = null;
                        units[i].row = coords.row;
                        units[i].column = coords.column;
                        table[units[i].row][units[i].column] = units[i];
                    }
                }

            for (int m = 1; m <= 3; ++m) {
                Coords coords = new Coords(units[0].row + dr[units[0].direction] * m, units[0].column + dc[units[0].direction] * m);
                if (!coords.isValidRange())
                    break;
                else if (table[coords.row][coords.column] == null)
                    continue;

                int id = table[coords.row][coords.column].id;
                Unit[] newUnits = new Unit[17];
                Unit[][] newTable = new Unit[4][4];
                for (int i = 0; i < 17; ++i)
                    if (units[i] != null) {
                        newUnits[i] = units[i].copy();
                        newTable[newUnits[i].row][newUnits[i].column] = newUnits[i];
                    }

                newTable[newUnits[0].row][newUnits[0].column] = null;
                newTable[coords.row][coords.column] = newUnits[0];
                newUnits[0].row = coords.row;
                newUnits[0].column = coords.column;
                newUnits[0].direction = newUnits[id].direction;
                newUnits[id] = null;

                queue.offer(new Status(status.score + id, newUnits, newTable));
            }
        }

        return maxScore;
    }
}
