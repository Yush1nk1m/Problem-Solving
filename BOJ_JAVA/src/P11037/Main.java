package P11037;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static String line;
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialization(0, 0, 0);
        Collections.sort(list);
        while ((line = br.readLine()) != null)
            sb.append(binarySearch(Integer.parseInt(line))).append('\n');
        System.out.println(sb);
    }

    public static void initialization(int depth, int number, int visited) {
        list.add(number);
        if (depth == 9)
            return;
        number *= 10;
        for (int adder = 1; adder < 10; ++adder)
            if ((visited & (1 << adder)) == 0)
                initialization(depth + 1, number + adder, visited | (1 << adder));
    }

    public static int binarySearch(int number) {
        int l = 0, r = list.size() - 1, ret = Integer.MAX_VALUE;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (list.get(m) > number) {
                ret = Math.min(ret, list.get(m));
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret == Integer.MAX_VALUE ? 0 : ret;
    }
}
