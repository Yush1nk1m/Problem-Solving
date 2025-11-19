package P16987;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static int[] S, W;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        S = new int[N];
        W = new int[N];
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            S[i] = Integer.parseInt(tokens[0]);
            W[i] = Integer.parseInt(tokens[1]);
        }
        System.out.println(DFS(0));
    }

    public static int DFS(int curr) {
        if (curr == N)
            return 0;
        else if (S[curr] <= 0)
            return DFS(curr + 1);

        int maxBroken = 0;
        for (int target = 0; target < N; ++target)
            if (target != curr && S[target] > 0) {
                int broken = 0;
                S[curr] -= W[target];
                S[target] -= W[curr];
                if (S[curr] <= 0)
                    ++broken;
                if (S[target] <= 0)
                    ++broken;
                maxBroken = Math.max(maxBroken, broken + DFS(curr + 1));
                S[target] += W[curr];
                S[curr] += W[target];
            }

        return maxBroken;
    }
}
