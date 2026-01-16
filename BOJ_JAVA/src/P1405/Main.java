package P1405;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static double east, west, south, north;
    static boolean[][] visited = new boolean[30][30];

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        east = Double.parseDouble(tokens[1]) / 100.0;
        west = Double.parseDouble(tokens[2]) / 100.0;
        south = Double.parseDouble(tokens[3]) / 100.0;
        north = Double.parseDouble(tokens[4]) / 100.0;
        System.out.print(DFS(N, 15, 15));
    }

    public static double DFS(int hop, int x, int y) {
        if (hop == 0)
            return 1;

        double p = 0;

        visited[x][y] = true;
        if (!visited[x - 1][y])
            p += west * DFS(hop - 1, x - 1, y);
        if (!visited[x + 1][y])
            p += east * DFS(hop - 1, x + 1, y);
        if (!visited[x][y - 1])
            p += south * DFS(hop - 1, x, y - 1);
        if (!visited[x][y + 1])
            p += north * DFS(hop - 1, x, y + 1);
        visited[x][y] = false;

        return p;
    }
}
