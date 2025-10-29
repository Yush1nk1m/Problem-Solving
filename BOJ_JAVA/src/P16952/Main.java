package P16952;

import java.io.*;
import java.util.*;

public class Main {

    static class Cost {
        int move, shift;

        public Cost(int move, int shift) {
            this.move = move;
            this.shift = shift;
        }

        public Cost add(Cost other) {
            return new Cost(move + other.move, shift + other.shift);
        }

        public static Cost min(Cost c1, Cost c2) {
            if (c1.move == c2.move)
                return c1.shift <= c2.shift ? c1 : c2;
            return c1.move < c2.move ? c1 : c2;
        }
    }

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static class Status {
        Cost cost;
        Coords coords;
        int number, piece;

        public Status(Cost cost, Coords coords, int number, int piece) {
            this.cost = cost;
            this.coords = coords;
            this.number = number;
            this.piece = piece;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int KNIGHT = 0;
    static final int ROOK = 1;
    static final int BISHOP = 2;
    static final int INF = 100_000_000;

    static int N;
    static int[][] table;
    static Coords[] coords;
    static Cost result;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        table = new int[N][N];
        coords = new Coords[N * N + 1];
        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < N; ++c) {
                table[r][c] = Integer.parseInt(tokens[c]);
                coords[table[r][c]] = new Coords(r, c);
            }
        }
        result = solve();
        System.out.println(result.move + " " + result.shift);
    }

    public static Cost solve() {
        Cost[][][][] cost = new Cost[N][N][3][N * N + 1];   // [row][col][piece][number]
        Queue<Status> queue = new LinkedList<>();

        cost[coords[1].r][coords[1].c][KNIGHT][1] = new Cost(0, 0);
        cost[coords[1].r][coords[1].c][ROOK][1] = new Cost(0, 0);
        cost[coords[1].r][coords[1].c][BISHOP][1] = new Cost(0, 0);
        queue.offer(new Status(cost[coords[1].r][coords[1].c][KNIGHT][1], coords[1], 1, KNIGHT));
        queue.offer(new Status(cost[coords[1].r][coords[1].c][ROOK][1], coords[1], 1, ROOK));
        queue.offer(new Status(cost[coords[1].r][coords[1].c][BISHOP][1], coords[1], 1, BISHOP));

        while (!queue.isEmpty()) {
            Status currStatus = queue.poll();
            Cost currCost = currStatus.cost;
            Coords currCoords = currStatus.coords;
            int number = currStatus.number, piece = currStatus.piece;
            if (number == N * N)
                continue;

            for (Coords nextCoords : getKnightNext(currCoords)) {
                int r = nextCoords.r, c = nextCoords.c;
                int m = piece == KNIGHT ? currCost.move + 1 : currCost.move + 2;
                int s = piece == KNIGHT ? currCost.shift : currCost.shift + 1;
                int nextNumber = table[r][c] == number + 1 ? number + 1 : number;
                Cost nextCost = new Cost(m, s);
                if (cost[r][c][KNIGHT][nextNumber] == null || Cost.min(cost[r][c][KNIGHT][nextNumber], nextCost) == nextCost) {
                    cost[r][c][KNIGHT][nextNumber] = nextCost;
                    queue.offer(new Status(nextCost, nextCoords, nextNumber, KNIGHT));
                }
            }

            for (Coords nextCoords : getRookNext(currCoords)) {
                int r = nextCoords.r, c = nextCoords.c;
                int m = piece == ROOK ? currCost.move + 1 : currCost.move + 2;
                int s = piece == ROOK ? currCost.shift : currCost.shift + 1;
                int nextNumber = table[r][c] == number + 1 ? number + 1 : number;
                Cost nextCost = new Cost(m, s);
                if (cost[r][c][ROOK][nextNumber] == null || Cost.min(cost[r][c][ROOK][nextNumber], nextCost) == nextCost) {
                    cost[r][c][ROOK][nextNumber] = nextCost;
                    queue.offer(new Status(nextCost, nextCoords, nextNumber, ROOK));
                }
            }

            for (Coords nextCoords : getBishopNext(currCoords)) {
                int r = nextCoords.r, c = nextCoords.c;
                int m = piece == BISHOP ? currCost.move + 1 : currCost.move + 2;
                int s = piece == BISHOP ? currCost.shift : currCost.shift + 1;
                int nextNumber = table[r][c] == number + 1 ? number + 1 : number;
                Cost nextCost = new Cost(m, s);
                if (cost[r][c][BISHOP][nextNumber] == null || Cost.min(cost[r][c][BISHOP][nextNumber], nextCost) == nextCost) {
                    cost[r][c][BISHOP][nextNumber] = nextCost;
                    queue.offer(new Status(nextCost, nextCoords, nextNumber, BISHOP));
                }
            }
        }

        int r = coords[N * N].r, c = coords[N * N].c;
        Cost minCost = new Cost(INF, INF);
        if (cost[r][c][KNIGHT][N * N] != null)
            minCost = Cost.min(minCost, cost[r][c][KNIGHT][N * N]);
        if (cost[r][c][ROOK][N * N] != null)
            minCost = Cost.min(minCost, cost[r][c][ROOK][N * N]);
        if (cost[r][c][BISHOP][N * N] != null)
            minCost = Cost.min(minCost, cost[r][c][BISHOP][N * N]);
        return minCost;
    }

    public static List<Coords> getKnightNext(Coords start) {
        List<Coords> list = new ArrayList<>();
        int[] dr = new int[]{-2, -2, -1, -1, 1, 1, 2, 2};
        int[] dc = new int[]{-1, 1, -2, 2, -2, 2, -1, 1};

        for (int d = 0; d < 8; ++d) {
            int r = start.r + dr[d], c = start.c + dc[d];
            if (isValidPoint(r, c))
                list.add(new Coords(r, c));
        }

        return list;
    }

    public static List<Coords> getRookNext(Coords start) {
        List<Coords> list = new ArrayList<>();

        for (int i = 0; i < N; ++i) {
            list.add(new Coords(start.r, i));
            list.add(new Coords(i, start.c));
        }

        return list;
    }

    public static List<Coords> getBishopNext(Coords start) {
        List<Coords> list = new ArrayList<>();

        for (int i = 1; i < N; ++i) {
            if (isValidPoint(start.r + i, start.c + i))
                list.add(new Coords(start.r + i, start.c + i));
            if (isValidPoint(start.r + i, start.c - i))
                list.add(new Coords(start.r + i, start.c - i));
            if (isValidPoint(start.r - i, start.c + i))
                list.add(new Coords(start.r - i, start.c + i));
            if (isValidPoint(start.r - i, start.c - i))
                list.add(new Coords(start.r - i, start.c - i));
        }

        return list;
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
}
