package P16712;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M;
    static int[] participants;
    static int[] ranks;
    static List<Integer> list = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        participants = new int[N];
        ranks = new int[N - M + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            participants[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N - M + 1; i++)
            ranks[i] = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M - 1; i++)
            list.add(participants[i]);

        for (int i = 0; i < ranks.length; i++) {
            list.add(participants[M - 1 + i]);
            Collections.sort(list);
            list.remove(ranks[i] - 1);
        }

        for (int a : list)
            sb.append(a).append(' ');

        System.out.println(sb.toString());
    }
}
