package P9702;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int T, N;
    static int[] array = new int[500];
    static List<Integer> list = new ArrayList<>(500);

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; ++i) {
            N = Integer.parseInt(br.readLine());
            for (int j = 0; j < N; ++j)
                array[j] = Integer.parseInt(br.readLine());
            System.out.println("Case #" + i + ": " + solve());
        }
    }

    public static int solve() {
        int total = 0;
        for (int i = 0; i < N; ++i)
            total += LIS(i);
        return total;
    }

    public static int LIS(int from) {
        int total = 0;
        list.clear();
        list.add(0);
        for (int i = from; i < N; ++i) {
            int index;
            if ((index = binarySearch(list, array[i])) == list.size())
                list.add(array[i]);
            else
                list.set(index, Math.min(list.get(index), array[i]));
            total += list.size() - 1;
        }
        return total;
    }

    public static int binarySearch(List<Integer> list, int target) {
        int l = 0, h = list.size() - 1, ret = list.size();
        while (l <= h) {
            int m = (l + h) >> 1;
            if (list.get(m) >= target) {
                ret = Math.min(ret, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }
}
