package P30504;

import java.io.*;
import java.util.*;

public class Main {

    static class Required implements Comparable<Required> {
        int day, amount;

        public Required(int day, int amount) {
            this.day = day;
            this.amount = amount;
        }

        public int getDay() {
            return day;
        }

        public int getAmount() {
            return amount;
        }

        public int compareTo(Required other) {
            return amount - other.amount;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static Required[] req;
    static int[] sup, result;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        req = new Required[N];
        sup = new int[N];
        result = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            req[i] = new Required(i, Integer.parseInt(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            sup[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(req);
        Arrays.sort(sup);

        for (int i = 0; i < N; i++) {
            if (req[i].getAmount() > sup[i]) {
                bw.write("-1");
                bw.close();
                br.close();
                return;
            }
            result[req[i].getDay()] = sup[i];
        }

        for (int amount : result)
            bw.write(String.valueOf(amount) + ' ');
        bw.close();
        br.close();
    }
}
