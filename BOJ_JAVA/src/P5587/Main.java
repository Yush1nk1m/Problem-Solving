package P5587;

import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        boolean[] myCard = new boolean[n * 2 + 1];
        List<Integer> c1 = new LinkedList<>();
        List<Integer> c2 = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            myCard[Integer.parseInt(br.readLine())] = true;
        }

        for (int i = 1; i <= n * 2; i++) {
            if (myCard[i])
                c1.add(i);
            else
                c2.add(i);
        }

        boolean turn = false;
        int currCard = c1.get(0);
        c1.remove(0);
        Outer: while (!c1.isEmpty() && !c2.isEmpty()) {
            if (turn) {
                turn = false;
                for (int i = 0; i < c1.size(); i++)
                    if (c1.get(i) > currCard) {
                        currCard = c1.get(i);
                        c1.remove(i);
                        continue Outer;
                    }
            } else {
                turn = true;
                for (int i = 0; i < c2.size(); i++)
                    if (c2.get(i) > currCard) {
                        currCard = c2.get(i);
                        c2.remove(i);
                        continue Outer;
                    }
            }
            currCard = 0;
        }

        bw.write(String.valueOf(c2.size()));
        bw.write('\n');
        bw.write(String.valueOf(c1.size()));
        br.close();
        bw.close();
    }
}
