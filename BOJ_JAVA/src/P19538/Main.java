package P19538;

import java.io.*;
import java.util.*;

public class Main {

    private static final int NONE = -1;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static List<List<Integer>> graph = new ArrayList<>();
    private static int[] times;
    private static Queue<Integer> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
        
        times = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            times[i] = NONE;
        }

        for (int i = 1; i <= N; i++) {
            String[] tokens = br.readLine().split(" ");
            for (String token : tokens) {
                int neighbor = Integer.parseInt(token);
                if (neighbor != 0) {
                    graph.get(i).add(neighbor);
                }
            }
        }

        int M = Integer.parseInt(br.readLine());
        String[] tokens = br.readLine().split(" ");
        for (String token : tokens) {
            int node = Integer.parseInt(token);
            q.offer(node);
            times[node] = 0;
        }

        int t = 0;
        while (!q.isEmpty()) {
            t++;

            List<Integer> candidates = new ArrayList<>();

            int qSize = q.size();
            while (qSize-- > 0) {
                int curr = q.poll();

                for (int neighbor : graph.get(curr)) {
                    if (times[neighbor] == NONE && canBelieve(neighbor)) {
                        candidates.add(neighbor);
                        q.offer(neighbor);
                    }
                }
            }

            for (int candidate : candidates) {
                times[candidate] = t;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            sb.append(times[i]);
            sb.append(' ');
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }

    private static boolean canBelieve(int node) {
        int count = 0;
        for (int neighbor : graph.get(node)) {
            if (times[neighbor] != NONE) {
                count++;
            }
        }

        int size = graph.get(node).size();
        if (size % 2 == 0) {
            return size / 2 <= count;
        } else {
            return size / 2 < count;
        }
    }
}
