package P15558;

import java.io.*;
import java.util.*;

public class Main {

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final char AVAILABLE = '1';
    static final int LEFT = 0;
    static final int RIGHT = 1;

    static int N, k;
    static char[][] table = new char[2][];
    static boolean[][] visited = new boolean[2][];
    static Queue<Pair> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        k = Integer.parseInt(tokens[1]);
        for (int i = 0; i < 2; ++i) {
            table[i] = br.readLine().toCharArray();
            visited[i] = new boolean[N];
        }
        System.out.print(solve());
    }

    public static int solve() {
        int time = 0;
        visited[LEFT][0] = true;
        queue.offer(new Pair(LEFT, 0));
        while (!queue.isEmpty()) {
            int size = queue.size();
            ++time;
            while (size-- > 0) {
                Pair p = queue.poll();
                if (p.second + 1 >= N || p.second + k >= N)
                    return 1;

                if (p.second - 1 >= 0 && table[p.first][p.second - 1] == AVAILABLE && !visited[p.first][p.second - 1] && p.second - 1 >= time) {
                    visited[p.first][p.second - 1] = true;
                    queue.offer(new Pair(p.first, p.second - 1));
                }
                if (p.second + 1 < N && table[p.first][p.second + 1] == AVAILABLE && !visited[p.first][p.second + 1] && p.second + 1 >= time) {
                    visited[p.first][p.second + 1] = true;
                    queue.offer(new Pair(p.first, p.second + 1));
                }
                if (p.second + k < N && table[1 - p.first][p.second + k] == AVAILABLE && !visited[1 - p.first][p.second + k] && p.second + k >= time) {
                    visited[1 - p.first][p.second + k] = true;
                    queue.offer(new Pair(1 - p.first, p.second + k));
                }
            }
        }
        return 0;
    }
}
