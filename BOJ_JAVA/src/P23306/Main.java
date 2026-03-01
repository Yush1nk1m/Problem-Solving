package P23306;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        bw.write("? " + N + "\n");
        bw.flush();
        int result = Integer.parseInt(br.readLine());
        bw.write("? 1\n");
        bw.flush();
        result -= Integer.parseInt(br.readLine());
        bw.write("! " + result);
        bw.flush();
    }
}
