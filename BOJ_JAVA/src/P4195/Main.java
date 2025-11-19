package P4195;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int t, f, id;
    static int[] parent = new int[200001];
    static int[] count = new int[200001];
    static Map<String, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            solve();
        System.out.println(sb);
    }

    public static void solve() throws IOException {
        f = Integer.parseInt(br.readLine());
        initialize(f * 2);
        while (f-- > 0) {
            tokens = br.readLine().split(" ");
            sb.append(getNetworkSize(tokens[0], tokens[1])).append('\n');
        }
    }

    public static void initialize(int size) {
        id = 0;
        for (int i = 0; i < size + 1; ++i) {
            parent[i] = i;
            count[i] = 1;
        }
        map.clear();
    }

    public static int getNetworkSize(String p1, String p2) {
        if (!map.containsKey(p1))
            map.put(p1, id++);
        if (!map.containsKey(p2))
            map.put(p2, id++);

        int id1 = map.get(p1), id2 = map.get(p2);
        if (find(id1, id2)) {
            while (id1 != parent[id1])
                id1 = parent[id1];
            return count[id1];
        } else {
            return union(id1, id2);
        }
    }

    public static boolean find(int id1, int id2) {
        while (id1 != parent[id1])
            id1 = parent[id1];

        while (id2 != parent[id2])
            id2 = parent[id2];

        return id1 == id2;
    }

    public static int union(int id1, int id2) {
        Queue<Integer> queue = new LinkedList<>();

        while (id1 != parent[id1]) {
            queue.offer(id1);
            id1 = parent[id1];
        }

        while (id2 != parent[id2]) {
            queue.offer(id2);
            id2 = parent[id2];
        }

        queue.offer(id2);
        count[id1] += count[id2];

        while (!queue.isEmpty()) {
            int id = queue.poll();
            parent[id] = id1;
            count[id] = count[id1];
        }

        return count[id1];
    }
}
