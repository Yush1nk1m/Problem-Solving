package P2661;

import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static boolean found = false;
    static char[] array;
    static String result;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        array = new char[N];
        DFS(0);
        System.out.print(result);
    }

    public static void DFS(int index) {
        if (index == N) {
            found = true;
            result = buildString(array, 0, array.length);
            return;
        } else if (found) {
            return;
        }

        Outer: for (char c = '1'; c <= '3' && !found; ++c) {
            array[index] = c;
            for (int size = 1; size <= (index + 1) >> 1; ++size)
               if (buildString(array, index - size + 1, index + 1)
                       .equals(buildString(array, index - (size << 1) + 1, index - size + 1)))
                   continue Outer;
            DFS(index + 1);
        }
    }

    public static String buildString(char[] array, int start, int end) {
        StringBuilder sb = new StringBuilder();
        for (int i = start; i < end; ++i)
            sb.append(array[i]);
        return sb.toString();
    }
}
