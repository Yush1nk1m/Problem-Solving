package P30389;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static String[] strings;
    static Map<String, Integer> suffixCount = new HashMap<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        strings = new String[N];
        for (int i = 0; i < N; i++)
            strings[i] = br.readLine();

        for (String s : strings)
            for (int i = s.length() - 1; i >= 0; i--) {
                String key = s.substring(i);
                suffixCount.put(key, suffixCount.getOrDefault(key, 0) + 1);
            }

        int result = 0;
        for (int count : suffixCount.values())
            if (count % 2 == 1)
                result++;

        System.out.println(result);
    }
}
