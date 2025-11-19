package P15823;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, size, l, h;
    static int[] card;
    static boolean[] visited = new boolean[500001];

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        card = new int[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            card[i] = Integer.parseInt(tokens[i]);
        l = 1;
        h = N;
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                size = Math.max(size, m);
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        System.out.println(size);
    }

    public static boolean check(int size) {
        Arrays.fill(visited, false);
        int l = 0, r = 0, count = 0;
        while (l <= r && r < N) {
            if (!visited[card[r]]) {
                visited[card[r++]] = true;
                if (r - l == size) {
                    if (++count == M)
                        return true;
                    while (l < r)
                        visited[card[l++]] = false;
                }
            } else {
                visited[card[l++]] = false;
            }
        }
        return false;
    }
}
