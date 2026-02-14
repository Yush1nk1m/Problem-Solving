package P1461;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static final int INF = 100_000_000;

    static int N, M;
    static List<Integer> positive = new ArrayList<>(), negative = new ArrayList<>();
    static int[] posTable, negTable;

    public static void main(String[] args) throws IOException {
        positive.add(0);
        negative.add(0);
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);

        tokens = br.readLine().split(" ");
        for (String token : tokens) {
            int loc = Integer.parseInt(token);
            if (loc > 0)
                positive.add(loc << 1);
            else
                negative.add(-loc << 1);
        }

        Collections.sort(positive);
        Collections.sort(negative);
        if (positive.get(positive.size() - 1) > negative.get(negative.size() - 1))
            positive.set(positive.size() - 1, positive.get(positive.size() - 1) >> 1);
        else
            negative.set(negative.size() - 1, negative.get(negative.size() - 1) >> 1);

        posTable = new int[positive.size()];
        negTable = new int[negative.size()];
        Arrays.fill(posTable, INF);
        Arrays.fill(negTable, INF);
        posTable[0] = negTable[0] = 0;
        for (int i = 1; i < posTable.length; ++i)
            for (int j = i - 1; j >= 0 && j >= i - M; --j)
                posTable[i] = Math.min(posTable[i], positive.get(i) + posTable[j]);
        for (int i = 1; i < negTable.length; ++i)
            for (int j = i - 1; j >= 0 && j >= i - M; --j)
                negTable[i] = Math.min(negTable[i], negative.get(i) + negTable[j]);

        System.out.print(posTable[posTable.length - 1] + negTable[negTable.length - 1]);
    }
}
