package P3109;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final char BLOCKED = 'x';

    static int R, C;
    static char[][] table;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    public static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        R = Integer.parseInt(tokens[0]);
        C = Integer.parseInt(tokens[1]);
        visited = new boolean[R][C];
        table = new char[R][];
        for (int r = 0; r < R; ++r)
            table[r] = br.readLine().toCharArray();
    }

    public static int solve() {
        int count = 0;
        for (int r = 0; r < R; ++r)
            if (DFS(r, 0))
                ++count;
        return count;
    }

    public static boolean DFS(int r, int c) {
        visited[r][c] = true;
        if (c == C - 1)
            return true;

        for (int d = -1; d <= 1; ++d)
            if (isValidPoint(r + d, c + 1) && !visited[r + d][c + 1] && DFS(r + d, c + 1))
                return true;
        return false;
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C && table[r][c] != BLOCKED;
    }
}
