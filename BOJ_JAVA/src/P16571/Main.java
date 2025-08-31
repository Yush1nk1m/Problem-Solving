package P16571;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int getR() {
            return r;
        }

        public int getC() {
            return c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int EMPTY = 0;
    static final int X = 1;
    static final int O = 2;
    static final int NONE = 3;
    static final int LOSE = 0;
    static final int DRAW = 1;
    static final int WIN = 2;

    static int player;
    static int[][] board = new int[3][3];
    static List<Coords> empties = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        for (int r = 0; r < 3; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < 3; c++) {
                board[r][c] = Integer.parseInt(st.nextToken());
                if (board[r][c] == EMPTY)
                    empties.add(new Coords(r, c));
            }
        }
        player = getTurn();

        switch (dfs(0, player)) {
            case LOSE:
                System.out.print("L");
                break;
            case DRAW:
                System.out.print("D");
                break;
            case WIN:
                System.out.print("W");
                break;
        }
    }

    public static int getTurn() {
        int x = 0, o = 0;
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++) {
                if (board[r][c] == X)
                    x++;
                else if (board[r][c] == O)
                    o++;
            }
        return x == o ? X : O;
    }

    public static int getWinner() {
        for (int i = 0; i < 3; i++) {
            // ith row
            if (board[i][0] == X && board[i][1] == X && board[i][2] == X)
                return X;
            if (board[i][0] == O && board[i][1] == O && board[i][2] == O)
                return O;
            // ith col
            if (board[0][i] == X && board[1][i] == X && board[2][i] == X)
                return X;
            if (board[0][i] == O && board[1][i] == O && board[2][i] == O)
                return O;
        }
        // right-lower diagonal
        if (board[0][0] == X && board[1][1] == X && board[2][2] == X)
            return X;
        if (board[0][0] == O && board[1][1] == O && board[2][2] == O)
            return O;
        // right-upper diagonal
        if (board[2][0] == X && board[1][1] == X && board[0][2] == X)
            return X;
        if (board[2][0] == O && board[1][1] == O && board[0][2] == O)
            return O;

        return NONE;
    }

    public static int dfs(int mask, int turn) {
        int winner;
        if (mask == (1 << empties.size()) - 1) {
            winner = getWinner();
            return winner == NONE ? DRAW : winner == turn ? WIN : LOSE;
        } else if ((winner = getWinner()) != NONE) {
            return winner == turn ? WIN : LOSE;
        }

        int result = NONE;
        for (int i = 0; i < empties.size(); i++)
            if ((mask & (1 << i)) == 0) {
                mask |= (1 << i);
                Coords coords = empties.get(i);
                board[coords.getR()][coords.getC()] = turn;
                result = Math.min(result, dfs(mask, turn == X ? O : X));
                board[coords.getR()][coords.getC()] = EMPTY;
                mask ^= (1 << i);
            }

        return switch (result) {
            case WIN -> LOSE;
            case LOSE -> WIN;
            default -> DRAW;
        };
    }
}
