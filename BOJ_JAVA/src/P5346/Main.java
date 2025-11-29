package P5346;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n;

    public static void main(String[] args) throws IOException {
        while ((n = Integer.parseInt(br.readLine())) != 0)
            sb.append((n + 1) >> 1).append('\n');
        System.out.println(sb);
    }
}
