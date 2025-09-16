package P2631;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int[] arr;
    static List<Integer> LIS = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(br.readLine());
        LIS.add(arr[0]);
        for (int i = 1; i < N; i++) {
            int j = -Collections.binarySearch(LIS, arr[i]) - 1;
            if (LIS.size() == j)
                LIS.add(arr[i]);
            else
                LIS.set(j, arr[i]);
        }
        System.out.println(N - LIS.size());
    }
}
