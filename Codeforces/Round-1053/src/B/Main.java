package B;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int t, n, m;
    static String command;
    static Set<Integer> blackSet;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve();
            sb.append(blackSet.size()).append('\n');
            for (int i : blackSet)
                sb.append(i).append(' ');
            sb.append('\n');
        }
        System.out.println(sb);
    }

    public static void solve() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        command = br.readLine();
        st = new StringTokenizer(br.readLine());
        blackSet = new HashSet<>();
        for (int i = 0; i < m; i++)
            blackSet.add(Integer.parseInt(st.nextToken()));

        int x = 1;
        for (int i = 0; i < n; i++) {
            if (command.charAt(i) == 'A') {
                ++x;
                if (!blackSet.contains(x))
                    blackSet.add(x);
            } else if (command.charAt(i) == 'B') {
                int y = x + 1;
                while (blackSet.contains(y))
                    ++y;
                x = y;
                blackSet.add(x++);
                while (blackSet.contains(x))
                    ++x;
            }
        }
    }
}
