package P2012;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        List<Integer> expected = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            expected.add(Integer.parseInt(br.readLine()));
        }
        expected.sort(null);

        long total = 0;
        int rank = 1;
        for (int n : expected) {
            total += Math.abs(rank - n);
            rank++;
        }

        System.out.println(total);
    }
}
