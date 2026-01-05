package P12355;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static String[] tokens;

    static int T, N;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; ++i) {
            N = Integer.parseInt(br.readLine());
            tokens = br.readLine().split(" ");
            sb.append("Case #").append(i).append(": ").append(solve()).append('\n');
        }
        System.out.print(sb);
    }

    public static int solve() {
        List<Integer> list = new ArrayList<>();
        list.add(0);

        for (String token : tokens) {
            int number = Integer.parseInt(token);
            int index = binarySearch(list, number);
            if (index == list.size())
                list.add(number);
            else
                list.set(index, number);
        }

        return N - list.size() + 1;
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
