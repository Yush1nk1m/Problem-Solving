package P12738;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, index;
    static int[] array;
    static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        array = new int[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            array[i] = Integer.parseInt(tokens[i]);
        list.add(-1000000001);
        for (int number : array) {
            if ((index = higher(list, number)) == list.size())
                list.add(number);
            else
                list.set(index, Math.min(list.get(index), number));
        }
        System.out.print(list.size() - 1);
    }

    public static int higher(List<Integer> list, int target) {
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
