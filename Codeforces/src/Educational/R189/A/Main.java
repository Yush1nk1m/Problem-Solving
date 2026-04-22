package Educational.R189.A;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int t;
    static long x, y;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            x = Long.parseLong(st.nextToken());
            y = Long.parseLong(st.nextToken());
            sb.append(y / x == 2 ? "NO\n" : "YES\n");
        }
        System.out.println(sb);
    }
}
