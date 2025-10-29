package P17142;

import java.io.*;
import java.util.*;

class Main {

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static class Table {

        static int[] dr = new int[]{-1, 0, 1, 0};
        static int[] dc = new int[]{0, -1, 0, 1};

        int size, totalCell;
        int[][] status;
        boolean[][] visited;
        List<Coords> viruses = new ArrayList<>();

        public Table(int size) {
            this.size = size;
            status = new int[size + 2][size + 2];
            visited = new boolean[size + 2][size + 2];
            for (boolean[] row : visited)
                Arrays.fill(row, true);
            totalCell = size * size;
        }

        public void initialize() throws IOException {
            for (int r = 1; r <= size; r++) {
                tokens = br.readLine().split(" ");
                for (int c = 1; c <= size; c++) {
                    status[r][c] = Integer.parseInt(tokens[c - 1]);
                    if (status[r][c] == 1)
                        --totalCell;
                    else if (status[r][c] == 2)
                        viruses.add(new Coords(r, c));
                }
            }
        }

        public void clearVisited() {
            for (int r = 1; r <= size; r++)
                for (int c = 1; c <= size; c++)
                    if (status[r][c] != 1)
                        visited[r][c] = false;
        }

        public int BFS(int mask) {
            int remainedCell = totalCell - viruses.size();
            Queue<Coords> queue = new LinkedList<>();
            clearVisited();

            for (int i = 0; i < viruses.size(); i++)
                if ((mask & (1 << i)) != 0) {
                    visited[viruses.get(i).r][viruses.get(i).c] = true;
                    queue.offer(viruses.get(i));
                }

            int time = 0;
            Outer: while (!queue.isEmpty() && remainedCell > 0) {
                ++time;
                int qSize = queue.size();
                while (qSize-- > 0) {
                    Coords curr = queue.poll();
                    for (int d = 0; d < 4; d++) {
                        int nr = curr.r + dr[d], nc = curr.c + dc[d];
                        if (!visited[nr][nc]) {
                            visited[nr][nc] = true;
                            queue.offer(new Coords(nr, nc));
                            if (status[nr][nc] == 0 && --remainedCell == 0)
                                break Outer;
                        }
                    }
                }
            }

            return remainedCell == 0 ? time : Integer.MAX_VALUE;
        }

        public int getVirusCount() {
            return viruses.size();
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, result;
    static Table table;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        table = new Table(N);
        table.initialize();
        result = DFS(0, 0, M);
        if (result == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(result);
    }

    public static int DFS(int i, int mask, int unselected) {
        if (unselected == 0)
            return table.BFS(mask);
        else if (i >= table.getVirusCount())
            return Integer.MAX_VALUE;

        return Math.min(DFS(i + 1, mask | (1 << i), unselected - 1), DFS(i + 1, mask, unselected));
    }
}
