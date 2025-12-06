package P15817;

import java.io.*;
import java.util.*;

public class Main {

    static class Pipe {
        int length, count;

        public Pipe(int length, int count) {
            this.length = length;
            this.count = count;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int NONE = -1;

    static int N, x;
    static Pipe[] pipes;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        x = Integer.parseInt(tokens[1]);
        pipes = new Pipe[N];
        cache = new int[N][x + 1];
        for (int[] row : cache)
            Arrays.fill(row, NONE);
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            pipes[i] = new Pipe(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
        }
        System.out.println(DFS(0, x));
    }

    public static int DFS(int type, int length) {
        if (length == 0)
            return 1;
        else if (type == N || length < 0)
            return 0;
        else if (cache[type][length] != NONE)
            return cache[type][length];

        cache[type][length] = 0;
        for (int c = pipes[type].count; c >= 0; --c)
            cache[type][length] += DFS(type + 1, length - pipes[type].length * c);
        return cache[type][length];
    }
}
