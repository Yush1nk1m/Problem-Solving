package P25178;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int[] count = new int[('z' - 'a' + 1)];
    static String s1, s2;
    static StringBuilder sb1 = new StringBuilder();
    static StringBuilder sb2 = new StringBuilder();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        s1 = br.readLine();
        s2 = br.readLine();
        if (validation(s1, s2))
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    public static boolean validation(String s1, String s2) {
        if (s1.charAt(0) != s2.charAt(0) || s1.charAt(N - 1) != s2.charAt(N - 1))
            return false;

        for (int i = 0; i < N; ++i) {
            if (isVowel(s1.charAt(i)))
                ++count[s1.charAt(i) - 'a'];
            else
                sb1.append(s1.charAt(i));
            if (isVowel(s2.charAt(i)))
                --count[s2.charAt(i) - 'a'];
            else
                sb2.append(s2.charAt(i));
        }

        if (!sb1.toString().equals(sb2.toString()))
            return false;

        for (int c : count)
            if (c != 0)
                return false;

        return true;
    }

    public static boolean isVowel(char c) {
        return c == 'a'  || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
