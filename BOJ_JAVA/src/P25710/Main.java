package P25710;

import java.io.*;
import java.util.*;

public class Main {

    static class Info implements Comparable<Info> {
        int a, b, score;

        public Info(int a, int b) {
            this.a = a;
            this.b = b;
            calculateScore();
        }

        public void calculateScore() {
            int sum = a * b;
            while (sum > 0) {
                score += sum % 10;
                sum /= 10;
            }
        }

        public boolean isAvailable(int[] count) {
            boolean result = false;
            --count[a];
            --count[b];
            if (count[a] >= 0 && count[b] >= 0)
                result = true;
            ++count[a];
            ++count[b];
            return result;
        }

        public int compareTo(Info o) {
            return Integer.compare(o.score, score);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N;
    static List<Info> list = new ArrayList<>();
    static int[] count = new int[1000];

    public static void main(String[] args) throws IOException {
        initialize();

        N = Integer.parseInt(br.readLine());
        tokens = br.readLine().split(" ");
        for (String token : tokens)
            ++count[Integer.parseInt(token)];

        for (Info info : list)
            if (info.isAvailable(count)) {
                System.out.print(info.score);
                break;
            }
    }

    public static void initialize() {
        for (int a = 1; a <= 999; ++a)
            for (int b = a; b <= 999; ++b)
                list.add(new Info(a, b));
        Collections.sort(list);
    }
}
