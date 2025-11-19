package P23326;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, Q, pos;
    static TreeSet<Integer> set = new TreeSet<>();
    static boolean[] checked;


    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        Q = Integer.parseInt(tokens[1]);
        checked = new boolean[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            if (1 == Integer.parseInt(tokens[i])) {
                checked[i] = true;
                set.add(i);
            }
        while (Q-- > 0) {
            tokens = br.readLine().split(" ");
            switch (Integer.parseInt(tokens[0])) {
                case 1:
                    toggle(Integer.parseInt(tokens[1]) - 1);
                    break;
                case 2:
                    move(Integer.parseInt(tokens[1]));
                    break;
                default:
                    sb.append(getNearest()).append('\n');
                    break;
            }
        }
        System.out.println(sb);
    }

    public static void toggle(int i) {
        if (checked[i])
            set.remove(i);
        else
            set.add(i);
        checked[i] = !checked[i];
    }

    public static void move(int x) {
        pos = (pos + (x % N)) % N;
    }

    public static int getNearest() {
        if (checked[pos])
            return 0;
        else if (set.isEmpty())
            return -1;

        Integer next = set.higher(pos);
        if (next != null)
            return next - pos;
        next = set.first();
        return N + next - pos;
    }
}
