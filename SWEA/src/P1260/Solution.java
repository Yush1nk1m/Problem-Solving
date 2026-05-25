package P1260;

import java.io.*;
import java.util.*;

public class Solution {

    static class Matrix {
        int row, column;

        public Matrix(int row, int column) {
            this.row = row;
            this.column = column;
        }

        public String toString() {
            return "[" + row + " X " + column + "]";
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;

    static int t, n;
    static int[][] table, cache = new int[20][20];
    static boolean[][] visited;
    static List<Matrix> list = new ArrayList<>();
    static List<Matrix> ordered = new ArrayList<>();
    static Set<Matrix> appended = new HashSet<>();
    static Deque<Matrix> deque = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int x = 1; x <= t; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        table = new int[n][n];
        visited = new boolean[n][n];
        for (int r = 0; r < n; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < n; ++c)
                if ((table[r][c] = Integer.parseInt(st.nextToken())) == 0)
                    visited[r][c] = true;
        }
        for (int[] row : cache)
            Arrays.fill(row, NONE);
        list.clear();
        appended.clear();
        deque.clear();
        ordered.clear();
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                if (!visited[r][c])
                    list.add(findMatrix(r, c));
        arrangeList();
        sb.append(DFS(0, list.size() - 1)).append('\n');
    }

    private static Matrix findMatrix(int r, int c) {
        int re = r, ce = c;
        while (re < n && !visited[re][c])
            ++re;
        while (ce < n && !visited[r][ce])
            ++ce;

        for (int i = r; i < re; ++i)
            for (int j = c; j < ce; ++j)
                visited[i][j] = true;

        return new Matrix(re - r, ce - c);
    }

    private static void arrangeList() {
        for (Matrix matrix : list) {
            appended.add(matrix);
            deque.offerLast(matrix);
            if (arrange(matrix))
                return;
            deque.pollLast();
            appended.remove(matrix);
        }
    }

    private static boolean arrange(Matrix curr) {
        if (deque.size() == list.size()) {
            ordered.addAll(deque);
            return true;
        }

        boolean ret = false;
        for (Matrix next : list)
            if (!appended.contains(next) && deque.peekLast().column == next.row) {
                appended.add(next);
                deque.offerLast(next);
                ret |= arrange(next);
                deque.pollLast();
                appended.remove(next);
            }
        return ret;
    }

    private static int DFS(int left, int right) {
        if (left == right)
            return 0;
        else if (left == right - 1)
            return ordered.get(left).row * ordered.get(left).column * ordered.get(right).column;
        else if (cache[left][right] != NONE)
            return cache[left][right];

        cache[left][right] = Integer.MAX_VALUE;
        for (int i = left; i < right; ++i)
            cache[left][right] = Math.min(
                    cache[left][right],
                    DFS(left, i) + DFS(i + 1, right) + ordered.get(left).row * ordered.get(i).column * ordered.get(right).column);

        return cache[left][right];
    }
}
