package P23284;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] cache;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        cache = new int[N];
    }

    private static void solve() {
        DFS(0,1,0);
        System.out.print(sb);
    }

    private static void DFS(int index, int number, int mask) {
        if (index == N && mask == 0) {
            for (int n : cache)
                sb.append(n).append(' ');
            sb.append('\n');
            return;
        }

        for (int p = number - 1; p >= 1; --p)
            if ((mask & (1 << p)) != 0) {
                cache[index] = p;
                DFS(index + 1, number, mask ^ (1 << p));
                break;
            }
        if (number <= N)
            DFS(index, number + 1, mask | (1 << number));
    }
}
