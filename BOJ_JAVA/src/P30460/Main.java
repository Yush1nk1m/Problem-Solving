package P30460;

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static int[] table;
    static Map<Integer, Integer> cache = new HashMap<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        table = new int[N + 3];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            table[i] = Integer.parseInt(st.nextToken());
        bw.write(String.valueOf(dfs(0)));

        bw.close();
        br.close();
    }

    public static int dfs(int i) {
        if (i >= N)
            return 0;
        else if (cache.containsKey(i))
            return cache.get(i);

        cache.put(i, Math.max(table[i] + dfs(i + 1), (table[i] + table[i + 1] + table[i + 2]) * 2 + dfs(i + 3)));
        return cache.get(i);
    }
}
