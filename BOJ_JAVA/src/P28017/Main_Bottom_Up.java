package P28017;

import java.io.*;
import java.util.*;

public class Main_Bottom_Up {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int NONE = 100_000_000;

    static int N, M;
    static int[][] time;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        time = new int[N + 1][M];
        for (int r = 1; r <= N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < M; ++c)
                time[r][c] = Integer.parseInt(st.nextToken());
        }
        for (int round = 1; round <= N; ++round)
            for (int weapon = 0; weapon < M; ++weapon) {
                int minTime = Integer.MAX_VALUE;
                for (int prevWeapon = 0; prevWeapon < M; ++prevWeapon)
                    if (weapon != prevWeapon)
                        minTime = Math.min(minTime, time[round - 1][prevWeapon]);
                time[round][weapon] += minTime;
            }
        int minTime = Integer.MAX_VALUE;
        for (int w = 0; w < M; ++w)
            minTime = Math.min(minTime, time[N][w]);
        System.out.println(minTime);
    }
}
