package P3010;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final char CHIP = 'o';
    static final char EMPTY = '.';
    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static int bound, count;
    static char[][] board = new char[7][];

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 7; i++)
            board[i] = br.readLine().toCharArray();
        for (int r = 0; r < 7; r++)
            for (int c = 0; c < 7; c++)
                bound += board[r][c] == CHIP ? 1 : 0;
        for (int r = 0; r < 7; r++)
            for (int c = 0; c < 7; c++)
                if (board[r][c] == CHIP)
                    for (int d = 0; d < 4; d++)
                        if (isValidPoint(r + dr[d] * 2, c + dc[d] * 2) &&
                                board[r + dr[d]][c + dc[d]] == CHIP && board[r + dr[d] * 2][c + dc[d] * 2] == EMPTY)
                            ++count;
        System.out.println(count);
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < 7 && 0 <= c && c < 7;
    }
}
