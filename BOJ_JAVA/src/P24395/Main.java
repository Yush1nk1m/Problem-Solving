package P24395;

import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int red, blue, danger, id;

        public Node(int red, int blue, int danger) {
            this.red = red;
            this.blue = blue;
            this.danger = danger;
        }

        public int compareTo(Node other) {
            return Integer.compare(danger, other.danger);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static final int NONE = -1;
    static final int UNABLE = -100_000_000;

    static int N, M;
    static Node[] diseases, students;
    static int[][][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        diseases = new Node[M];
        for (int i = 0; i < M; ++i) {
            tokens = br.readLine().split(" ");
            diseases[i] = new Node(
                    Integer.parseInt(tokens[0]),
                    Integer.parseInt(tokens[1]),
                    Integer.parseInt(tokens[2])
            );
        }
        students = new Node[N];
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            students[i] = new Node(
                    Integer.parseInt(tokens[0]),
                    Integer.parseInt(tokens[1]),
                    0
            );
        }
        cache = new int[M][51][51];
        for (int[][] mat : cache)
            for (int[] row : mat)
                Arrays.fill(row, NONE);
    }

    private static void solve() {
        for (int i = 0; i < N; ++i) {
            students[i].id = i + 1;
            students[i].danger = Math.max(students[i].danger, DFS(0, students[i].red, students[i].blue));
        }
        Arrays.sort(students);
        for (Node student : students)
            sb.append(student.id).append(' ').append(student.danger).append('\n');
        System.out.print(sb);
    }

    private static int DFS(int i, int red, int blue) {
        if (red == 0 && blue == 0)
            return 0;
        else if (i == M || red < 0 || blue < 0)
            return UNABLE;
        else if (cache[i][red][blue] != NONE)
            return cache[i][red][blue];

        cache[i][red][blue] = UNABLE;
        if (diseases[i].red <= red && diseases[i].blue <= blue)
            cache[i][red][blue] = Math.max(
                    cache[i][red][blue],
                    diseases[i].danger + DFS(i + 1, red - diseases[i].red, blue - diseases[i].blue)
            );

        return cache[i][red][blue] = Math.max(
                cache[i][red][blue],
                DFS(i + 1, red, blue)
        );
    }
}
