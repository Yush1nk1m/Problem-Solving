package Educational.R189.B;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int t;

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        while (t-- > 0)
            solve(br.readLine());
        System.out.print(sb);
    }

    private static void solve(String line) {
        char[] arr = line.toCharArray();
        char pos = arr[0];
        int i = 0;

        while (i < arr.length) {
            if (arr[i] != pos) {
                while (i < arr.length && arr[i] != pos) {
                    arr[i] = arr[i] == 'a' ? 'b' : 'a';
                    pos = pos == 'a' ? 'b' : 'a';
                    ++i;
                }
                break;
            } else {
                ++i;
                pos = pos == 'a' ? 'b' : 'a';
            }
        }

        pos = arr[0];
        i = 0;
        while (i < arr.length) {
            if (arr[i] != pos) {
                sb.append("NO\n");
                return;
            }
            pos = pos == 'a' ? 'b' : 'a';
            ++i;
        }

        sb.append("YES\n");
    }
}
