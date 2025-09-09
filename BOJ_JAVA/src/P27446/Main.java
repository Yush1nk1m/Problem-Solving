package P27446;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int NONE = -1;
    static int N, M, lastIdx = NONE, cost;
    static boolean[] page;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        page = new boolean[N + 1];
        st = new StringTokenizer(br.readLine());
        while (M-- > 0)
            page[Integer.parseInt(st.nextToken())] = true;
        for (int i = 1; i <= N; i++)
            if (!page[i]) {
                cost += (lastIdx == NONE || (i - lastIdx) * 2 > 7) ? 7 : (i - lastIdx) * 2;
                lastIdx = i;
            }
        System.out.println(cost);
    }
}
