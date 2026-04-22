package P19238;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords implements Comparable<Coords> {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int compareTo(Coords other) {
            if (r == other.r)
                return Integer.compare(c, other.c);
            return Integer.compare(r, other.r);
        }
    }

    static class Guest implements Comparable<Guest> {
        Coords src, dest;

        public Guest(Coords src, Coords dest) {
            this.src = src;
            this.dest = dest;
        }

        public int compareTo(Guest other) {
            return src.compareTo(other.src);
        }
    }

    static class Info {
        Guest guest;
        int toGuest, toDest;

        public Info(Guest guest, int toGuest, int toDest) {
            this.guest = guest;
            this.toGuest = toGuest;
            this.toDest = toDest;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int INF = 1_000_000_000;
    static final int[] dr = {-1, 0, 1, 0};
    static final int[] dc = {0, -1, 0, 1};

    static int N, M, fuel;
    static int[][] table;
    static Coords driver;
    static List<Guest> guests = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        fuel = Integer.parseInt(st.nextToken());

        table = new int[N + 1][N + 1];
        for (int r = 1; r <= N; ++r) {
            st = new StringTokenizer(br.readLine());
            for (int c = 1; c <= N; ++c)
                table[r][c] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        driver = new Coords(
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken()));

        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            guests.add(new Guest(
                    new Coords(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())),
                    new Coords(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()))
            ));
        }
        Collections.sort(guests);
    }

    private static int solve() {
        while (fuel > 0 && !guests.isEmpty()) {
            Info info = findNextGuest();
            if (fuel - info.toGuest - info.toDest < 0)
                return -1;
            guests.remove(info.guest);
            fuel = fuel - info.toGuest + info.toDest;
            driver = info.guest.dest;
        }

        return guests.isEmpty() ? fuel : -1;
    }

    private static Info findNextGuest() {
        int distance;
        Info info = new Info(null, INF, INF);
        for (Guest guest : guests)
            if ((distance = getDistance(driver, guest.src)) < info.toGuest) {
                info.guest = guest;
                info.toGuest = distance;
            }
        if (info.guest != null)
            info.toDest = getDistance(info.guest.src, info.guest.dest);
        return info;
    }

    private static int getDistance(Coords src, Coords dest) {
        int distance = 0;
        boolean[][] visited = new boolean[N + 1][N + 1];
        Queue<Coords> queue = new LinkedList<>();

        visited[src.r][src.c] = true;
        queue.offer(src);
        while (!queue.isEmpty() && !visited[dest.r][dest.c]) {
            ++distance;
            int size = queue.size();
            while (size-- > 0) {
                Coords coords = queue.poll();
                for (int d = 0; d < 4; ++d) {
                    int r = coords.r + dr[d], c = coords.c + dc[d];
                    if (!isValidPoint(r, c) || visited[r][c])
                        continue;
                    visited[r][c] = true;
                    queue.offer(new Coords(r, c));
                }
            }
        }

        return visited[dest.r][dest.c] ? distance : INF;
    }

    private static boolean isValidPoint(int r, int c) {
        return 0 < r && r <= N && 0 < c && c <= N && table[r][c] != 1;
    }
}
