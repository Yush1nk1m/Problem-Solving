package P7571;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        List<Integer> r = new ArrayList<>(M);
        List<Integer> c = new ArrayList<>(M);

        for (int i = 0; i < M; i++) {
            r.add(sc.nextInt());
            c.add(sc.nextInt());
        }

        r.sort(null);
        c.sort(null);

        int rMid = r.get(M / 2);
        int cMid = c.get(M / 2);

        Long result = 0L;
        for (int i = 0; i < M; i++) {
            result += Math.abs(rMid - r.get(i)) + Math.abs(cMid - c.get(i));
        }

        System.out.println(result);
    }
}
