package P3865;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static String[] tokens;

    static int n;
    static String line, first;
    static Map<String, Set<String>> map = new HashMap<>();
    static Set<String> set = new HashSet<>();
    static Queue<String> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        while ((n = Integer.parseInt(br.readLine())) != 0)
            solve();
        System.out.print(sb);
    }

    private static void solve() throws IOException {
        map.clear();
        set.clear();
        for (int i = 0; i < n; ++i) {
            line = br.readLine();
            line = line.substring(0, line.length() - 1);
            tokens = line.split(":");
            map.put(tokens[0], new HashSet<>(Arrays.asList(tokens[1].split(","))));
            if (i == 0) first = tokens[0];
        }

        for (String member : map.get(first))
            if (map.containsKey(member) && !set.contains(member)) {
                set.add(member);
                queue.offer(member);
            }
        for (String member : set)
            map.get(first).remove(member);

        while (!queue.isEmpty()) {
            String group = queue.poll();
            for (String member : map.get(group)) {
                if (map.containsKey(member)) {
                    if (!set.contains(member)) {
                        set.add(member);
                        queue.offer(member);
                    }
                } else {
                    map.get(first).add(member);
                }
            }
        }

        sb.append(map.get(first).size()).append('\n');
    }
}
