package P30237;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int t, n;
    static int[] numberCount = new int[51];
    static Set<Long> sets;
    static Map<Integer, Set<Long>> setMap;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            sb.append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        int ret = 0;
        n = Integer.parseInt(br.readLine());
        sets = new HashSet<>();
        setMap = new HashMap<>();
        for (int i = 1; i <= 50; i++)
            setMap.put(i, new HashSet<>());
        Arrays.fill(numberCount, 0);
        for (int i = 0; i < n; ++i) {
            tokens = br.readLine().split(" ");
            int count = Integer.parseInt(tokens[0]);
            long mask = 0;
            for (int j = 1; j <= count; j++) {
                int number = Integer.parseInt(tokens[j]);
                mask |= (1L << number);
            }
            sets.add(mask);
            for (int j = 1; j <= count; j++) {
                int number = Integer.parseInt(tokens[j]);
                setMap.get(number).add(mask);
            }
        }

        for (int i = 1; i <= 50; i++)
            if (setMap.get(i).size() > 0) {
                long mask = 0;
                for (long set : sets)
                    if (!setMap.get(i).contains(set))
                        mask |= set;
                int bitCount = 0;
                for (int j = 1; j <= 50; j++)
                    if ((mask & (1L << j)) != 0)
                        ++bitCount;
                ret = Math.max(ret, bitCount);
            }

        return ret;
    }
}
