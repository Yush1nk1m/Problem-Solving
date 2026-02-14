package P30391;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, K, id = 2;
    static Queue<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);
        while (id < K + 2) {
            sb.append(id).append(' ').append(1).append('\n');
            queue.offer(id++);
        }
        while (id <= N) {
            int curr = queue.poll();
            for (int i = 0; i < K - 1 && id <= N; ++i) {
                sb.append(id).append(' ').append(curr).append('\n');
                queue.offer(id++);
            }
        }
        System.out.print(sb);
    }
}
