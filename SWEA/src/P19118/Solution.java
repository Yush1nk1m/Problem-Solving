package P19118;

import java.io.*;
import java.util.*;

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int TC, N;
    static int[] height;
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        TC = Integer.parseInt(br.readLine());
        for (int x = 1; x <= TC; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        list.clear();
        N = Integer.parseInt(br.readLine());
        height = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            height[i] = Integer.parseInt(st.nextToken());
    }

    private static void solve(int x) {
        sb.append('#').append(x).append(' ').append(LIS()).append('\n');
    }

    private static int LIS() {
        for (int h : height) {
            int index = binarySearch(list, h);
            if (index == list.size())
                list.add(h);
            else
                list.set(index, h);
        }
        return N - list.size();
    }

    private static int binarySearch(List<Integer> list, int target) {
        int l = 0, h = list.size();
        while (l < h) {
            int m = (l + h) >> 1;
            if (list.get(m) > target)
                h = m;
            else if (list.get(m) < target)
                l = m + 1;
            else
                return m;
        }
        return h;
    }
}
