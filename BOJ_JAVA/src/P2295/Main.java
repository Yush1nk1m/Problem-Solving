package P2295;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static List<Integer> list = new ArrayList<>(), sum = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; ++i) {
            int number = Integer.parseInt(br.readLine());
            list.add(number);
        }
        Collections.sort(list);
    }

    private static void solve() {
        int d = 0;

        for (int i = 0; i < N; ++i)
            for (int j = i; j < N; ++j)
                sum.add(list.get(i) + list.get(j));
        Collections.sort(sum);

        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (exists(sum, list.get(j) - list.get(i)))
                    d = Math.max(d, list.get(j));

        System.out.print(d);
    }

    private static boolean exists(List<Integer> list, int target) {
        int l = 0, h = list.size() - 1;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (list.get(m) < target)
                l = m + 1;
            else if (list.get(m) > target)
                h = m - 1;
            else
                return true;
        }
        return false;
    }
}
