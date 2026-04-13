package P23950;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int T, N;
    static int[] A;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; ++i) {
            initialize();
            solve(i);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            A[i] = Integer.parseInt(tokens[i]);
    }

    private static void solve(int number) {
        int index = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        List<Integer> list = new ArrayList<>();

        for (int citation : A) {
            pq.offer(citation);
            while (!pq.isEmpty() && index >= pq.peek())
                pq.poll();
            index = Math.max(index, pq.size());
            list.add(index);
        }

        sb.append("Case #").append(number).append(": ");
        for (int i : list)
            sb.append(i).append(' ');
        sb.append('\n');
    }
}
