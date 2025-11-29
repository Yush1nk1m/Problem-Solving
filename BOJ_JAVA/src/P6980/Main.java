package P6980;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, L;
    static int[] arr = new int[50];

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            L = Integer.parseInt(br.readLine());
            tokens = br.readLine().split(" ");
            for (int i = 0; i < L; ++i)
                arr[i] = Integer.parseInt(tokens[i]);
            sb.append("Optimal train swapping takes ").append(solve()).append(" swaps.\n");
        }
        System.out.println(sb);
    }

    public static int solve() {
        int swap = 0;
        for (int i = L - 1; i > 0; --i)
            for (int j = 0; j < i; ++j)
                if (arr[j] > arr[j + 1]) {
                    ++swap;
                    int t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
        return swap;
    }
}
