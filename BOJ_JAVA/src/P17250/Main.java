package P17250;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N, M;
    static int[] planet, parent;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        planet = new int[N + 1];
        parent = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            planet[i] = Integer.parseInt(br.readLine());
            parent[i] = i;
        }
        while (M-- > 0) {
            tokens = br.readLine().split(" ");
            int v1 = Integer.parseInt(tokens[0]);
            int v2 = Integer.parseInt(tokens[1]);
            if (find(v1, v2)) {
                while (v1 != parent[v1])
                    v1 = parent[v1];
                bw.append(String.valueOf(planet[v1])).append('\n');
            } else {
                bw.append(String.valueOf(union(v1, v2))).append('\n');
            }
        }
        bw.flush();
    }

    public static boolean find(int v1, int v2) {
        while (v1 != parent[v1])
            v1 = parent[v1];
        while (v2 != parent[v2])
            v2 = parent[v2];
        return v1 == v2;
    }

    public static int union(int v1, int v2) {
        List<Integer> list = new ArrayList<>();

        while (v1 != parent[v1]) {
            list.add(v1);
            v1 = parent[v1];
        }
        while (v2 != parent[v2]) {
            list.add(v2);
            v2 = parent[v2];
        }
        list.add(v2);

        for (int v : list)
            parent[v] = v1;

        return planet[v1] += planet[v2];
    }
}
