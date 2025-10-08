package P12094;

import java.io.*;
import java.util.*;

public class Main {

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Board {
        static final int LEFT = 0;
        static final int RIGHT = 1;
        static final int UP = 2;
        static final int DOWN = 3;
        static final int UNCOMBINED = 0;
        static final int COMBINED = 1;
        int[][] status;
        int N;
        Deque<Pair> deque;

        public Board(int N) {
            this.N = N;
            status = new int[N][N];
            deque = new ArrayDeque<>(N);
        }

        public void initialize() throws IOException {
            for (int r = 0; r < N; r++) {
                tokens = br.readLine().split(" ");
                for (int c = 0; c < N; c++)
                    status[r][c] = Integer.parseInt(tokens[c]);
            }
        }

        public boolean moveLeft() {
            int[][] newStatus = new int[N][N];
            boolean coalesce = false;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++)
                    if (status[r][c] > 0) {
                        if (!deque.isEmpty() && deque.peekLast().first == status[r][c] && deque.peekLast().second != COMBINED) {
                            deque.pollLast();
                            deque.offerLast(new Pair(status[r][c] << 1, COMBINED));
                            coalesce = true;
                        } else {
                            deque.offerLast(new Pair(status[r][c], UNCOMBINED));
                        }
                    }
                for (int c = deque.size() - 1; c >= 0; c--)
                    newStatus[r][c] = deque.pollLast().first;
            }
            status = newStatus;
            return coalesce;
        }

        public boolean moveRight() {
            int[][] newStatus = new int[N][N];
            boolean coalesce = false;
            for (int r = 0; r < N; r++) {
                for (int c = N - 1; c >= 0; c--)
                    if (status[r][c] > 0) {
                        if (!deque.isEmpty() && deque.peekLast().first == status[r][c] && deque.peekLast().second != COMBINED) {
                            deque.pollLast();
                            deque.offerLast(new Pair(status[r][c] << 1, COMBINED));
                            coalesce = true;
                        } else {
                            deque.offerLast(new Pair(status[r][c], UNCOMBINED));
                        }
                    }
                for (int c = N - deque.size(); c < N; c++)
                    newStatus[r][c] = deque.pollLast().first;
            }
            status = newStatus;
            return coalesce;
        }

        public boolean moveUp() {
            int[][] newStatus = new int[N][N];
            boolean coalesce = false;
            for (int c = 0; c < N; c++) {
                for (int r = 0; r < N; r++)
                    if (status[r][c] > 0) {
                        if (!deque.isEmpty() && deque.peekLast().first == status[r][c] && deque.peekLast().second != COMBINED) {
                            deque.pollLast();
                            deque.offerLast(new Pair(status[r][c] << 1, COMBINED));
                            coalesce = true;
                        } else {
                            deque.offerLast(new Pair(status[r][c], UNCOMBINED));
                        }
                    }
                for (int r = deque.size() - 1; r >= 0; r--)
                    newStatus[r][c] = deque.pollLast().first;
            }
            status = newStatus;
            return coalesce;
        }

        public boolean moveDown() {
            int[][] newStatus = new int[N][N];
            boolean coalesce = false;
            for (int c = 0; c < N; c++) {
                for (int r = N - 1; r >= 0; r--)
                    if (status[r][c] > 0) {
                        if (!deque.isEmpty() && deque.peekLast().first == status[r][c] && deque.peekLast().second != COMBINED) {
                            deque.pollLast();
                            deque.offerLast(new Pair(status[r][c] << 1, COMBINED));
                            coalesce = true;
                        } else {
                            deque.offerLast(new Pair(status[r][c], UNCOMBINED));
                        }
                    }
                for (int r = N - deque.size(); r < N; r++)
                    newStatus[r][c] = deque.pollLast().first;
            }
            status = newStatus;
            return coalesce;
        }

        public boolean move(int dir) {
            switch (dir) {
                case LEFT: return moveLeft();
                case RIGHT: return moveRight();
                case UP: return moveUp();
                case DOWN: return moveDown();
            }
            return false;
        }

        public int[][] getStatus() {
            return status;
        }

        public void setStatus(int[][] status) {
            this.status = status;
        }

        public int getMax() {
            int ret = 0;
            for (int r = 0; r < N; r++)
                for (int c = 0; c < N; c++)
                    ret = Math.max(ret, status[r][c]);
            return ret;
        }

        public boolean isEqualStatus(int[][] other) {
            for (int r = 0; r < N; r++)
                for (int c = 0; c < N; c++)
                    if (status[r][c] != other[r][c])
                        return false;
            return true;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static int result;
    static Board board;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        board = new Board(N);
        board.initialize();
        result = Math.max(result, board.getMax());
        DFS(0);
        System.out.println(result);
    }

    public static void DFS(int depth) {
        int currMax = board.getMax();
        result = Math.max(result, currMax);
        if (depth == 10 || (currMax << (10 - depth)) <= result)
            return;

        for (int dir = 0; dir < 4; dir++) {
            int[][] prevStatus = board.getStatus();
            board.move(dir);
            if (!board.isEqualStatus(prevStatus)) {
                DFS(depth + 1);
                board.setStatus(prevStatus);
            }
        }
    }
}
