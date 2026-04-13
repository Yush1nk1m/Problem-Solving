package P1365;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static int[] sequence;
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        sequence = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i)
            sequence[i] = Integer.parseInt(st.nextToken());
    }

    private static void solve() {
        for (int number : sequence) {
            int index = binarySearch(number);
            if (index == list.size())
                list.add(number);
            else
                list.set(index, number);
        }

        System.out.print(N - list.size());
    }

    private static int binarySearch(int number) {
        int l = 0, r = list.size() - 1, index = list.size();
        while (l <= r) {
            int m = (l + r) >> 1;
            if (list.get(m) > number) {
                r = m - 1;
                index = Math.min(index, m);
            } else {
                l = m + 1;
            }
        }
        return index;
    }
}
