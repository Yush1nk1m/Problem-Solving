package P24621;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static int[] arr1, arr2;
    static boolean[] checked;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        arr1 = new int[N];
        arr2 = new int[N];
        checked = new boolean[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            arr1[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            arr2[i] = Integer.parseInt(st.nextToken());
    }

    private static void solve() {
        int count = 0, i1 = 0, i2 = 0;

        while (i1 < N && i2 < N) {
            while (checked[arr1[i1]])
                ++i1;

            checked[arr2[i2]] = true;
            if (arr2[i2] == arr1[i1])
                ++i1;
            else
                ++count;
            ++i2;
        }

        System.out.print(count);
    }
}
