package P27931;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static List<Integer> even = new ArrayList<>(), odd = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) {
            int value = Integer.parseInt(st.nextToken());
            if (value % 2 == 0)
                even.add(value);
            else
                odd.add(value);
        }
        Collections.sort(even);
        Collections.sort(odd);
    }

    private static void solve() {
        int oddMin = Integer.MAX_VALUE, evenMin = Integer.MAX_VALUE;
        for (int i = 1; i < odd.size(); ++i)
            evenMin = Math.min(evenMin, odd.get(i) - odd.get(i - 1));
        for (int i = 1; i < even.size(); ++i)
            evenMin = Math.min(evenMin, even.get(i) - even.get(i - 1));

        int pe = 0, po = 0;
        while (pe < even.size() && po < odd.size()) {
            oddMin = Math.min(oddMin, Math.abs(even.get(pe) - odd.get(po)));
            if (even.get(pe) < odd.get(po))
                ++pe;
            else
                ++po;
        }
        System.out.print((evenMin == Integer.MAX_VALUE ? -1 : evenMin) + " " + (oddMin == Integer.MAX_VALUE ? -1 : oddMin));
    }
}
