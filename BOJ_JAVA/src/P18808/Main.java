package P18808;

import java.io.*;

public class Main {

    private static int N, M, K;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String[] tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);

        Board board = new Board(N, M);
        while (K-- > 0) {
            tokens = br.readLine().split(" ");
            int row = Integer.parseInt(tokens[0]), col = Integer.parseInt(tokens[1]);

            Sticker sticker = new Sticker(row, col);
            for (int r = 0; r < row; r++) {
                tokens = br.readLine().split(" ");
                for (int c = 0; c < col; c++) {
                    int value = Integer.parseInt(tokens[c]);
                    if (value == 1) {
                        sticker.setStatus(r, c, true);
                    } else {
                        sticker.setStatus(r, c, false);
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                if (board.apply(sticker)) {
                    break;
                }
                sticker.rotate();
            }
        }

        bw.write(Integer.valueOf(board.count()).toString());
        bw.flush();
        bw.close();
    }

    static class Board {

        private int row;
        private int col;
        private boolean[][] visited;

        public Board(int row, int col) {
            this.row = row;
            this.col = col;
            visited = new boolean[row][col];
        }

        public boolean apply(Sticker sticker) {
            for (int startR = 0; startR <= row - sticker.getRow(); startR++) {
                for (int startC = 0; startC <= col - sticker.getCol(); startC++) {
                    boolean isApplicable = true;
                    for (int r = 0; r < sticker.getRow() && isApplicable; r++) {
                        for (int c = 0; c < sticker.getCol() && isApplicable; c++) {
                            if (sticker.getStatus(r, c) && visited[startR + r][startC + c]) {
                                isApplicable = false;
                            }
                        }
                    }

                    if (isApplicable) {
                        for (int r = 0; r < sticker.getRow(); r++) {
                            for (int c = 0; c < sticker.getCol(); c++) {
                                if (sticker.getStatus(r, c)) {
                                    visited[startR + r][startC + c] = true;
                                }
                            }
                        }

                        return true;
                    }
                }
            }
            return false;
        }

        public int count() {
            int count = 0;
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    if (visited[r][c]) {
                        count++;
                    }
                }
            }

            return count;
        }

        public void print() {
            System.out.println("Board(" + row + ", " + col + ")");
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    System.out.print(visited[r][c] + " ");
                }
                System.out.println();
            }
        }
    }

    static class Sticker {
        private int row;
        private int col;
        private boolean[][] table;

        public Sticker(int row, int col) {
            this.row = row;
            this.col = col;
            table = new boolean[row][col];
        }

        public int getRow() {
            return row;
        }

        public int getCol() {
            return col;
        }

        public boolean getStatus(int row, int col) {
            return table[row][col];
        }

        public void setStatus(int row, int col, boolean value) {
            table[row][col] = value;
        }

        public void rotate() {
            boolean[][] newTable = new boolean[col][row];

            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    newTable[c][row - r - 1] = table[r][c];
                }
            }

            int temp = row;
            row = col;
            col = temp;
            table = newTable;
        }

        public void print() {
            System.out.println("Sticker(" + row + ", " + col + ")");
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    System.out.print(table[r][c] + " ");
                }
                System.out.println();
            }
        }
    }
}
