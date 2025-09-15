package P15482;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static String word1, word2;
    static int[][] cache;

    public static void main(String[] args) throws IOException {
        word1 = br.readLine();
        word2 = br.readLine();
        System.out.println(LCA());
    }

    public static int LCA() {
        cache = new int[word1.length() + 1][word2.length() + 1];
        for (int i = 1; i < cache.length; i++)
            for (int j = 1; j < cache[0].length; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    cache[i][j] = cache[i - 1][j - 1] + 1;
                else
                    cache[i][j] = Math.max(cache[i - 1][j], cache[i][j - 1]);
            }
        return cache[word1.length()][word2.length()];
    }
}
