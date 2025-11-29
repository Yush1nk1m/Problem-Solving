package P25099;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n;
    static String word, hash;
    static Set<String> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        while (n-- > 0)
            if (!set.contains(hash = getHash(word = br.readLine()))) {
                set.add(hash);
                sb.append(word).append('\n');
            }
        System.out.println(sb);
    }

    public static String getHash(String word) {
        char[] sorted = word.toCharArray();
        Arrays.sort(sorted);
        return String.valueOf(sorted);
    }
}
