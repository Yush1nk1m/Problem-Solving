package P16568;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, a, b;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        a = Integer.parseInt(tokens[1]);
        b = Integer.parseInt(tokens[2]);
        visited = new boolean[N + 1];
    }

    private static void solve() {
        int t = 0;
        Queue<Integer> queue = new LinkedList<>();

        visited[0] = true;
        queue.offer(0);
        while (!queue.isEmpty()) {
            if (visited[N]) {
                System.out.print(t);
                return;
            }

            ++t;
            int size = queue.size();
            while (size-- > 0) {
                int curr = queue.poll();

                if (curr + 1 <= N && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    queue.offer(curr + 1);
                }
                if (curr + a + 1 <= N && !visited[curr + a + 1]) {
                    visited[curr + a + 1] = true;
                    queue.offer(curr + a + 1);
                }
                if (curr + b + 1 <= N && !visited[curr + b + 1]) {
                    visited[curr + b + 1] = true;
                    queue.offer(curr + b + 1);
                }
            }
        }
        System.out.print(t);
    }
}
