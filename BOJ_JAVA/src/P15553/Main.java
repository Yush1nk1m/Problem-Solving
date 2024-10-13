package P15553;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static long N, K, count, total;
    private static List<Long> T = new ArrayList<>();
    private static PriorityQueue<Long> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");
        N = Long.parseLong(input[0]);
        K = Long.parseLong(input[1]);

        T.add(Long.parseLong(br.readLine()));
        for (int i = 1; i < N; i++) {
            T.add(Long.parseLong(br.readLine()));
            pq.offer(T.get(i) - T.get(i - 1) + 1);
        }

        while (N > K) {
            long curr = pq.poll();
            total += curr;
            N--;
            count++;
        }
        total += (N - count);

        bw.write(Long.valueOf(total).toString());
        bw.flush();
        bw.close();
    }

}
