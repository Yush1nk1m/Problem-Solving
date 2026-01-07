package P21236;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int[] dx = {-1, 0, 1, 0};
    static final int[] dy = {0, -1, 0, 1};

    static int N, count;
    static int[][] placed = new int[1001][1001];
    static int[][] adjacent = new int[1001][1001];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            tokens = br.readLine().split(" ");
            int x = Integer.parseInt(tokens[0]);
            int y = Integer.parseInt(tokens[1]);
            placed[x][y] = 1;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (!isValidPoint(nx, ny))
                    continue;
                ++adjacent[nx][ny];
                if (placed[nx][ny] == 0)
                    continue;
                if (adjacent[nx][ny] == 3)
                    ++count;
                else if (adjacent[nx][ny] == 4)
                    --count;
            }
            if (adjacent[x][y] == 3)
                ++count;
            sb.append(count).append('\n');
        }
        System.out.print(sb);
    }

    public static boolean isValidPoint(int x, int y) {
        return 0 <= x && x <= 1000 && 0 <= y && y <= 1000;
    }
}
