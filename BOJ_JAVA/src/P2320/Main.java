package P2320;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int NONE = -1;

    static int N;
    static String[] words;
    static List<Integer>[] graph;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        words = new String[N];
        graph = new List[N];
        for (int i = 0; i < N; ++i)
            graph[i] = new ArrayList<>();
        cache = new int[N][1 << N];

        for (int i = 0; i < N; ++i)
            words[i] = br.readLine();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j && words[i].charAt(words[i].length() - 1) == words[j].charAt(0))
                    graph[i].add(j);
        for (int[] row : cache)
            Arrays.fill(row, NONE);
    }

    private static void solve() {
        int ret = 0;
        for (int i = 0; i < N; ++i)
            ret = Math.max(ret, DFS(i, 1 << i));
        System.out.print(ret);
    }

    private static int DFS(int curr, int visited) {
        if (visited == (1 << N) - 1)
            return words[curr].length();
        else if (cache[curr][visited] != NONE)
            return cache[curr][visited];

        cache[curr][visited] = words[curr].length();
        for (int next : graph[curr])
            if ((visited & (1 << next)) == 0)
                cache[curr][visited] = Math.max(
                        cache[curr][visited],
                        words[curr].length() + DFS(next, visited | (1 << next)));
        return cache[curr][visited];
    }
}
