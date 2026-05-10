package P1257;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T, K;
    static String line;
    static Set<String> set = new HashSet<>();
    static List<String> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        K = Integer.parseInt(br.readLine());
        line = br.readLine();
        set.clear();
        list.clear();
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ');
        for (int length = 1; length <= line.length(); ++length)
            for (int s = 0; s <= line.length() - length; ++s)
                if (!set.contains(line.substring(s, s + length))) {
                    set.add(line.substring(s, s + length));
                    list.add(line.substring(s, s + length));
                }
        Collections.sort(list);
        sb.append(K > list.size() ? "none" : list.get(K - 1)).append('\n');
    }
}
