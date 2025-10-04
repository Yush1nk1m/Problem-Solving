package P17492;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int EMPTY = 0;
    static final int PIECE = 2;
    static final int[] dr = new int[]{-1, -1, -1, 0, 1, 1, 1, 0};
    static final int[] dc = new int[]{-1, 0, 1, 1, 1, 0, -1, -1};

    static int N, size;
    static int[][] table;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        table = new int[N + 2][N + 2];
        for (int[] row : table)
            Arrays.fill(row, 1);
        for (int r = 1; r <= N; r++) {
            tokens = br.readLine().split(" ");
            for (int c = 1; c <= N; c++) {
                table[r][c] = Integer.parseInt(tokens[c - 1]);
                if (table[r][c] == PIECE)
                    ++size;
            }
        }
        if (DFS(0))
            System.out.println("Possible");
        else
            System.out.println("Impossible");
    }

    public static boolean DFS(int depth) {
        if (depth == size - 1)
            return true;

        boolean ret = false;
        for (int r = 1; r <= N; r++)
            for (int c = 1; c <= N; c++)
                if (table[r][c] == PIECE) {
                    table[r][c] = EMPTY;
                    for (int d = 0; d < 8; d++)
                        if (table[r + dr[d]][c + dc[d]] == PIECE && table[r + 2 * dr[d]][c + 2 * dc[d]] == EMPTY) {
                            table[r + dr[d]][c + dc[d]] = EMPTY;
                            table[r + 2 * dr[d]][c + 2 * dc[d]] = PIECE;
                            if (DFS(depth + 1))
                                ret = true;
                            table[r + dr[d]][c + dc[d]] = PIECE;
                            table[r + 2 * dr[d]][c + 2 * dc[d]] = EMPTY;
                        }
                    table[r][c] = PIECE;
                }
        return ret;
    }
}
