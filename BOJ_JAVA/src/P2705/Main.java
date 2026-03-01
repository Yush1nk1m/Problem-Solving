package P2705;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T;
    static int count[] = new int[1001];

    public static void main(String[] args) throws IOException {
        initialize();
        while (T-- > 0)
            sb.append(count[Integer.parseInt(br.readLine())]).append('\n');
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        T = Integer.parseInt(br.readLine());
        count[0] = 1;
        for (int number = 1; number <= 1000; ++number)
            for (int i = 0; i <= (number >> 1); ++i)
                count[number] += count[i];
    }
}
