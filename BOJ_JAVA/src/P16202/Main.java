package P16202;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int v1, v2, weight;

        public Edge(int v1, int v2, int weight) {
            this.v1 = v1;
            this.v2 = v2;
            this.weight = weight;
        }

        public int compareTo(Edge other) {
            return other.weight - weight;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M, K, x, y, ret;
    static List<Edge> edges = new ArrayList<>();
    static int[] disjointSet;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            edges.add(new Edge(x, y, i));
        }
        Collections.sort(edges);
        for (int i = 0; i < K; i++)
            sb.append(MST()).append(' ');
        System.out.println(sb);
    }

    public static int MST() {
        int removeIndex = -1, count = 0, totalWeight = 0;
        disjointSet = new int[N + 1];
        for (int i = 1; i <= N; i++)
            disjointSet[i] = i;
        for (int i = edges.size() - 1; i >= 0; i--)
            if (!find(edges.get(i).v1, edges.get(i).v2)) {
                union(edges.get(i).v1, edges.get(i).v2);
                totalWeight += edges.get(i).weight;
                removeIndex = Math.max(removeIndex, i);
                if (++count == N - 1)
                    break;
            }
        if (removeIndex != -1)
            edges.remove(removeIndex);
        return count == N - 1 ? totalWeight : 0;
    }

    public static boolean find(int v1, int v2) {
        while (v1 != disjointSet[v1])
            v1 = disjointSet[v1];
        while (v2 != disjointSet[v2])
            v2 = disjointSet[v2];
        return v1 == v2;
    }

    public static void union(int v1, int v2) {
        List<Integer> temp = new ArrayList<>();
        while (v1 != disjointSet[v1]) {
            temp.add(v1);
            v1 = disjointSet[v1];
        }
        while (v2 != disjointSet[v2]) {
            temp.add(v2);
            v2 = disjointSet[v2];
        }
        temp.add(v2);
        for (int v : temp)
            disjointSet[v] = v1;
    }
}
