package P4991;

import java.io.*;
import java.util.*;

class Main {

    static class Node {
        int r, c, id;

        public Node(int r, int c, int id) {
            this.r = r;
            this.c = c;
            this.id = id;
        }
    }

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static String line;
    static StringBuilder sb = new StringBuilder();

    static final char EMPTY = '.';
    static final char WALL = 'x';
    static final char CLEANER = 'o';
    static final int INF = 100_000_000;
    static final int NONE = -1;
    static final int[] dr = new int[]{-1, 0, 1, 0};
    static final int[] dc = new int[]{0, -1, 0, 1};

    static int w, h, id, startId;
    static char[][] table;
    static List<Node> nodes = new ArrayList<>();
    static int[][] distance, cache;

    public static void main(String[] args) throws IOException {
        while (true) {
            tokens = br.readLine().split(" ");
            if (tokens[0].equals("0") && tokens[1].equals("0"))
                break;
            w = Integer.parseInt(tokens[0]);
            h = Integer.parseInt(tokens[1]);
            table = new char[h][w];
            nodes.clear();
            id = 0;
            for (int r = 0; r < h; ++r) {
                line = br.readLine();
                for (int c = 0; c < w; ++c) {
                    table[r][c] = line.charAt(c);
                    if (table[r][c] != EMPTY && table[r][c] != WALL) {
                        if (table[r][c] == CLEANER)
                            startId = id;
                        nodes.add(new Node(r, c, id));
                        table[r][c] = (char) id;
                        ++id;
                    }
                }
            }
            cache = new int[nodes.size()][1 << nodes.size()];
            for (int[] row : cache)
                Arrays.fill(row, NONE);
            if (!updateDistance(id))
                sb.append(-1).append('\n');
            else
                sb.append(DFS(startId, 1 << startId)).append('\n');
        }
        System.out.println(sb);
    }

    public static boolean updateDistance(int nodeNumber) {
        distance = new int[nodeNumber][nodeNumber];
        for (int[] row : distance)
            Arrays.fill(row, INF);
        for (int i = 0; i < nodeNumber; ++i)
            distance[i][i] = 0;

        for (Node node : nodes)
            if (!updateDistanceRowByBFS(node))
                return false;

        return true;
    }

    public static boolean updateDistanceRowByBFS(Node node) {
        int d = 0;
        boolean connected = false;
        Queue<Coords> queue = new LinkedList<>();
        boolean[][] visited = new boolean[h][w];

        visited[node.r][node.c] = true;
        queue.offer(new Coords(node.r, node.c));
        while (!queue.isEmpty()) {
            ++d;
            int size = queue.size();
            while (size-- > 0) {
                Coords curr = queue.poll();
                for (int dir = 0; dir < 4; ++dir) {
                    int r = curr.r + dr[dir], c = curr.c + dc[dir];
                    if (!isValidPoint(r, c) || visited[r][c])
                        continue;
                    visited[r][c] = true;
                    queue.offer(new Coords(r, c));
                    if (table[r][c] != EMPTY) {
                        distance[node.id][(int) table[r][c]] = d;
                        connected = true;
                    }
                }
            }
        }

        return connected;
    }

    public static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < h && 0 <= c && c < w && table[r][c] != WALL;
    }

    public static int DFS(int curr, int mask) {
        if (mask == (1 << nodes.size()) - 1)
            return 0;
        else if (cache[curr][mask] != NONE)
            return cache[curr][mask];

        cache[curr][mask] = INF;
        for (int ngbr = 0; ngbr < nodes.size(); ++ngbr)
            if ((mask & (1 << ngbr)) == 0 && distance[curr][ngbr] != INF)
                cache[curr][mask] = Math.min(cache[curr][mask], distance[curr][ngbr] + DFS(ngbr, mask | (1 << ngbr)));

        return cache[curr][mask];
    }
}
