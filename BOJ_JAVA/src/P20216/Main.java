package P20216;

import java.io.*;
import java.util.*;

public class Main {

    static class Schedule implements Comparable<Schedule>{
        int start, duration;

        public Schedule(int start, int duration) {
            this.start = start;
            this.duration = duration;
        }

        public int compareTo(Schedule other) {
            return Integer.compare(start, other.start);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M, S, x, y;
    static List<Schedule> schedules = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.print(solve());
    }

    private static void initialize() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        schedules.add(new Schedule(0, 0));
        schedules.add(new Schedule(S, 0));
        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());
            schedules.add(new Schedule(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        Collections.sort(schedules);
    }

    private static int solve() {
        for (int i = 0; i < schedules.size() - 1; ++i) {
            int term = schedules.get(i + 1).start - schedules.get(i).start - schedules.get(i).duration;
            if (term >= M)
                return schedules.get(i).start + schedules.get(i).duration;
        }
        return -1;
    }
}
