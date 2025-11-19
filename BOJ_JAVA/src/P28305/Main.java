package P28305;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, T;
    static int[] day, slot;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        T = Integer.parseInt(tokens[1]);
        day = new int[N];
        slot = new int[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            day[i] = Integer.parseInt(tokens[i]);
        Arrays.sort(day);
        System.out.println(solve());
    }

    public static int solve() {
        int l = 1, h = N, minSlot = 200_001;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (validation(m)) {
                minSlot = Math.min(minSlot, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return minSlot;
    }

    public static boolean validation(int size) {
        for (int i = 0; i < size; ++i)
            slot[i] = 0;
        for (int i = 0; i < N; ++i) {
            if (slot[i % size] >= day[i])
                return false;
            slot[i % size] = Math.max(day[i], slot[i % size] + T);
        }
        return true;
    }
}
