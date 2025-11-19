package P22963;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] A, len, seq;
    static List<Integer> lis = new ArrayList<>();
    static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        tokens = br.readLine().split(" ");
        for (int i = 0; i < N; ++i)
            A[i] = Integer.parseInt(tokens[i]);

        LIS();

        if (lis.size() > N - 3) {
            buildString();
            System.out.println(sb);
        } else System.out.println("NO");
    }

    public static void LIS() {
        len = new int[N];
        lis.add(0);
        for (int i = 0; i < N; ++i) {
            int index = higher(lis, A[i]);
            if (index == lis.size())
                lis.add(A[i]);
            else
                lis.set(index, Math.min(lis.get(index), A[i]));
            len[i] = index;
        }
    }

    public static int higher(List<Integer> list, int target) {
        int l = 0, h = list.size() - 1, index = list.size();

        while (l <= h) {
            int m = (l + h) >> 1;
            if (list.get(m) > target) {
                index = Math.min(index, m);
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return index;
    }

    public static void buildString() {
        int i = N - 1, j = lis.size() - 1;
        sb.append("YES\n").append(N - lis.size() + 1).append('\n');
        seq = new int[lis.size()];

        while (len[i] != lis.size() - 1)
            --i;

        while (j > 0) {
            if (len[i] == j)
                seq[j--] = A[i--];
            else
                --i;
        }

        i = 0;
        j = 1;
        while (i < N && j < seq.length) {
            if (A[i] == seq[j]) {
                ++i;
                ++j;
            } else {
                sb.append(++i).append(' ').append(seq[j]).append('\n');
            }
        }
        --j;
        while (i < N)
            sb.append(++i).append(' ').append(seq[j]).append('\n');
    }
}
