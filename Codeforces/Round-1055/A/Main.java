package A;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int t;
    static Set<Integer> set;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            sb.append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        br.readLine();
        String[] tokens = br.readLine().split(" ");
        set = new HashSet<>();
        for (String token : tokens)
            set.add(Integer.parseInt(token));
        return 2 * set.size() - 1;
    }
}
