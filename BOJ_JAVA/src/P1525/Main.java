package P1525;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final String END = "123456780";
    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static StringBuilder sb;
    static char[][] table = new char[3][3];

    public static void main(String[] args) throws IOException {
        for (int r = 0; r < 3; ++r) {
            tokens = br.readLine().split(" ");
            for (int c = 0; c < 3; ++c)
                table[r][c] = tokens[c].charAt(0);
        }
        System.out.println(BFS());
    }

    public static int BFS() {
        int move = 0;
        Queue<String> queue = new LinkedList<>();
        Set<String> set = new HashSet<>();

        String expression = tableToString(table);
        set.add(expression);
        queue.offer(expression);

        while (!queue.isEmpty() && !set.contains(END)) {
            int size = queue.size();
            ++move;
            while (size-- > 0) {
                String curr = queue.poll();
                for (String next : getNextStates(curr))
                    if (!set.contains(next)) {
                        if (next.equals(END))
                            return move;
                        set.add(next);
                        queue.offer(next);
                    }
            }
        }

        return set.contains(END) ? move : -1;
    }

    public static String tableToString(char[][] table) {
        sb = new StringBuilder();
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                sb.append(table[r][c]);
        return sb.toString();
    }

    public static List<String> getNextStates(String expression) {
        List<String> list = new ArrayList<>();
        int zr = 0, zc = 0;
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c) {
                table[r][c] = expression.charAt(r * 3 + c);
                if (table[r][c] == '0') {
                    zr = r;
                    zc = c;
                }
            }

        for (int d = 0; d < 4; ++d) {
            int nr = zr + dr[d], nc = zc + dc[d];
            if (!isValidPoint(nr, nc))
                continue;
            swap(zr, zc, nr, nc);
            list.add(tableToString(table));
            swap(zr, zc, nr, nc);
        }

        return list;
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < 3 && 0 <= c && c < 3;
    }

    public static void swap(int r1, int c1, int r2, int c2) {
        char t = table[r1][c1];
        table[r1][c1] = table[r2][c2];
        table[r2][c2] = t;
    }
}
