package P25602;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, K;
    static int[] A;
    static int[][] R, M;
    static int maxSatisfaction;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        A = new int[N];
        R = new int[K][N];
        M = new int[K][N];
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; j++)
            A[j] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++)
                R[i][j] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++)
                M[i][j] = Integer.parseInt(st.nextToken());
        }
        DFS(0, 0);
        System.out.println(maxSatisfaction);
    }

    public static void DFS(int i, int satisfaction) {
        if (i == K) {
            maxSatisfaction = Math.max(maxSatisfaction, satisfaction);
            return;
        }
        for (int j1 = 0; j1 < N; j1++)
            for (int j2 = 0; j2 < N; j2++) {
                A[j1]--;
                A[j2]--;
                if (A[j1] >= 0 && A[j2] >= 0)
                    DFS(i + 1, satisfaction + R[i][j1] + M[i][j2]);
                A[j1]++;
                A[j2]++;
            }
    }
}
