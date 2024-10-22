package P1337;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static int N;
    private static List<Integer> numbers = new ArrayList<>();
    private static Integer minCount = 4;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(br.readLine()));
        }
        numbers.sort(null);
        numbers.add(0);

        for (int i = 0; i < N; i++) {
            int curr = numbers.get(i);
            int j = i + 1;
            int count = 0;
            for (int adder = 1; adder < 5; adder++) {
                if (numbers.get(j) == curr + adder) {
                    j++;
                } else {
                    count++;
                }
            }
            minCount = Math.min(minCount, count);
        }

        bw.write(minCount.toString());
        bw.flush();
        bw.close();
    }
}
