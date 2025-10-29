package P2931;

import java.io.*;
import java.util.*;

class Main {

    static class Node {
        static final int U = 1, L = 2, R = 4, D = 8;
        char value;
        int opened, visited;

        public Node(char value) {
            this.value = value;
            switch (value) {
                case '|':
                    opened = U | D;
                    break;
                case '-':
                    opened = L | R;
                    break;
                case '+':
                    opened = U | L | R | D;
                    break;
                case '1':
                    opened = R | D;
                    break;
                case '2':
                    opened = U | R;
                    break;
                case '3':
                    opened = U | L;
                    break;
                case '4':
                    opened = L | D;
                    break;
                default:
                    opened = 0;
                    break;
            }
        }

        public boolean isOpened(int dir) {
            return (opened & dir) != 0;
        }

        public boolean isVisited(int dir) {
            return (visited & dir) != 0;
        }

        public void open(int dir) {
            opened |= dir;
        }

        public void visit(int dir) {
            visited |= dir;
        }

        public void unvisit(int dir) {
            visited ^= dir;
        }

        public char convertVisitedToValue() {
            switch (visited) {
                case (U | D):
                    return '|';
                case (L | R):
                    return '-';
                case (U | L | R | D):
                    return '+';
                case (R | D):
                    return '1';
                case (U | R):
                    return '2';
                case (U | L):
                    return '3';
                case (L | D):
                    return '4';
                default:
                    return '.';
            }
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int[] dr = new int[]{-1, 0, 0, 1};
    static final int[] dc = new int[]{0, -1, 1, 0};
    static final int NONE = -1;

    static int R, C, mr, mc, zr, zc;
    static Node[][] table;
    static boolean found = false;

    public static void main(String[] args) throws IOException {
        String[] tokens = br.readLine().split(" ");
        R = Integer.parseInt(tokens[0]);
        C = Integer.parseInt(tokens[1]);
        table = new Node[R + 1][C + 1];
        for (int r = 1; r <= R; ++r) {
            String line = br.readLine();
            for (int c = 1; c <= C; ++c) {
                table[r][c] = new Node(line.charAt(c - 1));
                if (table[r][c].value == 'M') {
                    mr = r; mc = c;
                } else if (table[r][c].value == 'Z') {
                    zr = r; zc = c;
                }
            }
        }
        for (int d = 0; d < 4; ++d) {
            int r, c;

            r = mr + dr[d]; c = mc + dc[d];
            if (isValidPoint(r, c) && table[r][c].isOpened(1 << (3 - d)))
                table[mr][mc].open(1 << d);
            r = zr + dr[d]; c = zc + dc[d];
            if (isValidPoint(r, c) && table[r][c].isOpened(1 << (3 - d)))
                table[zr][zc].open(1 << d);
        }
        DFS(mr, mc, NONE, NONE);
    }

    public static boolean isValidPoint(int r, int c) {
        return 1 <= r && r <= R && 1 <= c && c <= C;
    }

    public static void DFS(int r, int c, int ur, int uc) {
        if (found) {
            return;
        } else if (r == zr && c == zc) {
            if (ur != NONE) {
                System.out.println(ur + " " + uc + " " + table[ur][uc].convertVisitedToValue());
                found = true;
            }
            return;
        } else if (table[r][c].value == '.') {
            return;
        }

        for (int dir = 0; dir < 4; ++dir)
            if (table[r][c].isOpened(1 << dir) && !table[r][c].isVisited(1 << dir)) {
                int nr = r + dr[dir], nc = c + dc[dir], reverseDir = 3 - dir;
                if (!isValidPoint(nr, nc))
                    continue;

                if (table[nr][nc].value == '.' && ur == NONE) {
                    table[nr][nc] = new Node('+');
                    table[r][c].visit(1 << dir);
                    table[nr][nc].visit(1 << reverseDir);
                    DFS(nr, nc, nr, nc);
                    table[r][c].unvisit(1 << dir);
                    table[nr][nc] = new Node('.');
                } else if (table[nr][nc].isOpened(1 << reverseDir) && !table[nr][nc].isVisited(1 << reverseDir)) {
                    table[r][c].visit(1 << dir);
                    table[nr][nc].visit(1 << reverseDir);
                    DFS(nr, nc, ur, uc);
                    table[nr][nc].unvisit(1 << reverseDir);
                    table[r][c].unvisit(1 << dir);
                }
            }
    }
}
