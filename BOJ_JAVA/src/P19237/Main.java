package P19237;

import java.io.*;
import java.util.*;

public class Main {

    static class Smell {
        int id, t;

        public Smell(int id, int t) {
            this.id = id;
            this.t = t;
        }
    }

    static class Shark implements Comparable<Shark> {
        int id, r, c, direction;
        int[][] priority = new int[4][4];

        public Shark(int id, int r, int c) {
            this.id = id;
            this.r = r;
            this.c = c;
        }

        public int compareTo(Shark other) {
            return Integer.compare(id, other.id);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int[] dr = {-1, 1, 0, 0};
    static final int[] dc = {0, 0, -1, 1};

    static int N, M, k;
    static List<Shark> sharks = new ArrayList<>();
    static Smell[][] smells;
    static Shark[][] sharkStatus;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        smells = new Smell[N][N];
        sharkStatus = new Shark[N][N];
        for (int r = 0; r < N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < N; ++c) {
                int id = Integer.parseInt(st.nextToken());
                if (id > 0) {
                    smells[r][c] = new Smell(id, 0);
                    Shark shark = new Shark(id, r, c);
                    sharks.add(shark);
                    sharkStatus[r][c] = shark;
                }
            }
        }
        Collections.sort(sharks);

        st = new StringTokenizer(br.readLine());
        for (Shark shark : sharks)
            shark.direction = Integer.parseInt(st.nextToken()) - 1;

        for (Shark shark : sharks) {
            for (int d = 0; d < 4; ++d) {
                st = new StringTokenizer(br.readLine());
                for (int i = 0; i < 4; ++i)
                    shark.priority[d][i] = Integer.parseInt(st.nextToken()) - 1;
            }
        }
    }

    private static int solve() {
        int time = 0;
        while (time <= 1000 && sharks.size() > 1) {
            ++time;
            leaveSharks();
            placeSharks(time);
            removeSmells(time);
        }
        return time <= 1000 ? time : -1;
    }

    private static void leaveSharks() {
        Outer: for (Shark shark : sharks) {
            sharkStatus[shark.r][shark.c] = null;
            for (int d : shark.priority[shark.direction]) {
                int r = shark.r + dr[d], c = shark.c + dc[d];
                if (!isValidPoint(r, c) || (smells[r][c] != null))
                    continue;
                shark.r = r;
                shark.c = c;
                shark.direction = d;
                continue Outer;
            }
            for (int d : shark.priority[shark.direction]) {
                int r = shark.r + dr[d], c = shark.c + dc[d];
                if (!isValidPoint(r, c) || (smells[r][c] != null && smells[r][c].id != shark.id))
                    continue;
                shark.r = r;
                shark.c = c;
                shark.direction = d;
                continue Outer;
            }
        }
    }

    private static void placeSharks(int time) {
        List<Shark> removed = new ArrayList<>();
        for (Shark shark : sharks) {
            if (sharkStatus[shark.r][shark.c] != null) {
                removed.add(shark);
                continue;
            }
            sharkStatus[shark.r][shark.c] = shark;
            smells[shark.r][shark.c] = new Smell(shark.id, time);
        }
        for (Shark shark : removed)
            sharks.remove(shark);
    }

    private static void removeSmells(int time) {
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                if (smells[r][c] != null && time - smells[r][c].t >= k)
                    smells[r][c] = null;
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }
}
