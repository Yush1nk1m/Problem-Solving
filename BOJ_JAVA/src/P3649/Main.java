package P3649;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String line;
        int x, n;

        while ((line = br.readLine()) != null) {
            x = Integer.parseInt(line) * 10000000;
            n = Integer.parseInt(br.readLine());

            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(Integer.parseInt(br.readLine()));
            }

            solve(list, x);
        }

        bw.flush();
        bw.close();
    }

    private static void solve(List<Integer> list, int target) throws IOException {
        list.sort(null);

        int i = 0, j = list.size() - 1;
        while (i < j) {
            if (list.get(i) + list.get(j) < target) {
                i++;
            } else if (list.get(i) + list.get(j) > target) {
                j--;
            } else {
                bw.write("yes " + list.get(i) + " " + list.get(j) + "\n");
                return;
            }
        }

        bw.write("danger\n");
    }
}
