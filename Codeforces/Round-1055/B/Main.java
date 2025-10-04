package B;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int t, n, rk, ck, rd, cd;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            sb.append(solve()).append('\n');
        System.out.println(sb);
    }

    public static int solve() throws IOException {
        String[] tokens = br.readLine().split(" ");
        n = Integer.parseInt(tokens[0]);
        rk = Integer.parseInt(tokens[1]);
        ck = Integer.parseInt(tokens[2]);
        rd = Integer.parseInt(tokens[3]);
        cd = Integer.parseInt(tokens[4]);
        int rMin = Integer.MAX_VALUE;
        int cMin = Integer.MAX_VALUE;

        if (rk < rd)
            rMin = Math.min(rMin, rd);
        else if (rk > rd)
            rMin = Math.min(rMin, n - rd);
        if (ck < cd)
            cMin = Math.min(cMin, cd);
        else if (ck > cd)
            cMin = Math.min(cMin, n - cd);

        rMin = rMin == Integer.MAX_VALUE ? 0 : rMin;
        cMin = cMin == Integer.MAX_VALUE ? 0 : cMin;

        return Math.max(rMin, cMin);
    }
}
