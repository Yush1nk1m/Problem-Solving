package P31265;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, result = -1;
    static boolean[] prev, curr;
    static Set<Integer>[] setList;
    static Queue<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        prev = new boolean[M + 1];
        curr = new boolean[M + 1];
        setList = new Set[N];
        tokens = br.readLine().split(" ");
        for (int r = 0; r < N; ++r)
            setList[r] = new HashSet<>();
        for (int r = 0; r < N; ++r) {
            tokens = br.readLine().split(" ");
            for (String token : tokens) {
                int item = Integer.parseInt(token);
                if (item <= M)
                    queue.offer(item);
                for (int e : setList[r])
                    if (e + item <= M)
                        queue.offer(e + item);
                while (!queue.isEmpty())
                    setList[r].add(queue.poll());
            }
        }
        for (int e : setList[0])
            prev[e] = true;
        for (int i = 1; i < N; ++i) {
            for (int e : setList[i])
                for (int t = M; t > e; --t)
                    if (prev[t - e])
                        curr[t] = true;
            System.arraycopy(curr, 0, prev, 0, M + 1);
            Arrays.fill(curr, false);
        }
        for (int i = M; i > 0; --i)
            if (prev[i]) {
                result = i;
                break;
            }
        System.out.println(result);
    }
}
