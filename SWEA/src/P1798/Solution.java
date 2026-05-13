package P1798;

import java.io.*;
import java.util.*;

public class Solution {

    static class Node {
        char type;
        int period, satisfaction;
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int INF = 100_000_000;

    static int T, N, M, airport;
    static int[][] distance;
    static Node[] nodes;
    static List<Integer> route = new ArrayList<>();
    static int maxSatisfaction;
    static List<Integer> maxPath = new ArrayList<>();
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int x = 1; x <= T; ++x) {
            initialize();
            solve(x);
        }
        System.out.print(sb);
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        distance = new int[N][N];
        for (int r = 0; r < N - 1; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = r + 1; c < N; ++c)
                distance[r][c] = distance[c][r] = Integer.parseInt(st.nextToken());
        }
        nodes = new Node[N];
        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            nodes[i] = new Node();
            if ((nodes[i].type = st.nextToken().charAt(0)) == 'P') {
                nodes[i].period = Integer.parseInt(st.nextToken());
                nodes[i].satisfaction = Integer.parseInt(st.nextToken());
            } else if (nodes[i].type == 'A') airport = i;
        }
        route.clear();
        visited = new boolean[N];
        maxSatisfaction = 0;
        maxPath.clear();
    }

    private static void solve(int x) {
        sb.append('#').append(x);
        DFS(airport, 0, 1, 0);
        sb.append(' ').append(maxSatisfaction);
        for (int point : maxPath)
            sb.append(' ').append((point + 1));
        sb.append('\n');
    }

    private static void DFS(int curr, int time, int day, int satisfaction) {
        if (day > M) return;

        for (int next = 0; next < N; ++next) {
            if (curr == next) continue;

            if (nodes[next].type == 'H' && time + distance[curr][next] <= 540) {
                route.add(next);
                DFS(next, 0, day + 1, satisfaction);
                route.remove(route.size() - 1);
            } else if (nodes[next].type == 'P' && !visited[next] && time + distance[curr][next] + nodes[next].period <= 540) {
                visited[next] = true;
                route.add(next);
                DFS(next, time + distance[curr][next] + nodes[next].period, day, satisfaction + nodes[next].satisfaction);
                route.remove(route.size() - 1);
                visited[next] = false;
            } else if (nodes[next].type == 'A' && day == M && time + distance[curr][next] <= 540 && satisfaction > maxSatisfaction) {
                route.add(next);
                maxSatisfaction = satisfaction;
                maxPath.clear();
                maxPath.addAll(route);
                route.remove(route.size() - 1);
            }
        }
    }
}
