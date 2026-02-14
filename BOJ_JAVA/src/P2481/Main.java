package P2481;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, K, M;
    static int[] value, parent;
    static Map<Integer, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);

        value = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            value[i] = convert(br.readLine());
            map.put(value[i], i);
        }

        parent = new int[N + 1];
        for (int i = 1; i <= N; ++i)
            parent[i] = i;
        preprocess();

        M = Integer.parseInt(br.readLine());
        while (M-- > 0)
            getPath(Integer.parseInt(br.readLine()));

        System.out.print(sb);
    }

    public static int convert(String line) {
        int total = 0;
        for (int i = line.length() - 1; i >= 0; --i)
            if (line.charAt(i) == '1')
                total += 1 << (line.length() - 1 - i);
        return total;
    }

    public static void preprocess() {
        boolean[] visited = new boolean[N + 1];
        Queue<Integer> queue = new LinkedList<>();

        visited[0] = visited[1] = true;
        queue.offer(1);
        while (!queue.isEmpty()) {
            int currId = queue.poll();
            int currValue = value[currId];
            for (int i = 0; i < K; ++i) {
                int nextId = map.getOrDefault(currValue ^ (1 << i), 0);
                if (visited[nextId])
                    continue;
                parent[nextId] = currId;
                visited[nextId] = true;
                queue.offer(nextId);
            }
        }
    }

    public static void getPath(int dest) {
        Stack<Integer> stack = new Stack<>();

        stack.push(dest);
        while (dest != parent[dest]) {
            dest = parent[dest];
            stack.push(dest);
        }

        if (stack.peek() != 1)
            sb.append("-1\n");
        else {
            while (!stack.isEmpty())
                sb.append(stack.pop()).append(' ');
            sb.append('\n');
        }
    }
}
