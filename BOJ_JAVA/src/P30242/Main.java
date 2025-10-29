package P30242;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] col;
    static boolean[] visited;
    static boolean found, duplicated;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        col = new int[N + 2];
        visited = new boolean[N + 1];
        tokens = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            col[i] = Integer.parseInt(tokens[i - 1]);
            if (col[i] > 0 && visited[col[i]])
                duplicated = true;
            visited[col[i]] = true;
        }
        if (!duplicated)
            DFS(1);
        if (!found)
            System.out.println(-1);
        else
            System.out.println(sb);
    }

    public static void DFS(int row) {
        if (found) {
            return;
        } else if (row >= N + 1) {
            for (int i = 1; i <= N; i++)
                sb.append(col[i]).append(' ');
            found = true;
            return;
        } else if (col[row] > 0) {
            DFS(row + 1);
            return;
        }

        Outer: for (int c = 1; c <= N && !found; c++) {
            if (visited[c])
                continue;
            int t1 = c, t2 = c, r = row;
            while (r <= N) {
                if ((t1 <= N && col[r] == t1) || (t2 > 0 && col[r] == t2))
                    continue Outer;
                r++;
                t1++;
                t2--;
            }
            t1 = c; t2 = c; r = row;
            while (r > 0) {
                if ((t1 <= N && col[r] == t1) || (t2 > 0 && col[r] == t2))
                    continue Outer;
                r--;
                t1++;
                t2--;
            }

            visited[c] = true;
            col[row] = c;
            DFS(row + 1);
            col[row] = 0;
            visited[c] = false;
        }
    }
}
