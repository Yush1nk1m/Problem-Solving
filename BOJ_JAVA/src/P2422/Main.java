package P2422;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static int N, M;
    private static boolean[][] graph;

    public static void main(String[] args) throws IOException {
        String[] tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);

        graph = new boolean[N + 1][N + 1];
        for (int r = 0; r <= N; r++) {
            for (int c = 0; c <= N; c++) {
                graph[r][c] = !graph[r][c];
            }
        }
        for (int i = 1; i <= N; i++) {
            graph[i][i] = false;
        }

        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            int i1 = Integer.parseInt(tokens[0]);
            int i2 = Integer.parseInt(tokens[1]);
            graph[i1][i2] = graph[i2][i1] = false;
        }

        bw.write(Integer.valueOf(dfs(0, 0, 0)).toString());
        bw.flush();
        bw.close();
    }

    private static int dfs(int prev, int i, int depth) {
        if (depth == 3) {
            return 1;
        } else if (i > N) {
            return 0;
        }

        int sum = 0;
        for (int next = i + 1; next <= N; next++) {
            if (graph[prev][next] && graph[i][next]) {
                sum += dfs(i, next, depth + 1);
            }
        }

        return sum;
    }
}
