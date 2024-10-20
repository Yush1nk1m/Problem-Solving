package P13909;

import java.io.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        long N = Long.parseLong(br.readLine());
        long i = 1, cnt = 0;
        while (Math.pow(i, 2) <= N) {
            i++;
            cnt++;
        }
        System.out.println(cnt);
    }
}
