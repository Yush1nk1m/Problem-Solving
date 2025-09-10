package P10713;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M;
    static long cost;
    static int[] P;
    static long[] A, B, C, used;

    public static void main(String args[]) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        P = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++)
            P[i] = Integer.parseInt(st.nextToken());

        A = new long[N];
        B = new long[N];
        C = new long[N];
        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            A[i] = Long.parseLong(st.nextToken());
            B[i] = Long.parseLong(st.nextToken());
            C[i] = Long.parseLong(st.nextToken());
        }

        used = new long[N + 1];
        for (int day = 0; day < M - 1; day++) {
            used[Math.min(P[day], P[day + 1])]++;
            used[Math.max(P[day], P[day + 1])]--;
        }
        for (int i = 1; i < used.length - 1; i++) {
            used[i] += used[i-1];
            cost += Math.min(A[i] * used[i], C[i] + used[i] * B[i]);
        }

        System.out.println(cost);

    }
}
