package P30827;

import java.io.*;
import java.util.*;

public class Main {

    private static final long INF = 1_000_000_001L;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static String[] tokens;
    private static int N, K;
    private static Meeting[] room;
    private static PriorityQueue<Meeting> pq = new PriorityQueue<>();
    private static int count = 0;

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);

        room = new Meeting[K];
        for (int i = 0; i < K; i++) {
            room[i] = new Meeting(0L, 0L);
        }

        for (int i = 0; i < N; i++) {
            tokens = br.readLine().split(" ");
            pq.offer(new Meeting(
                    Long.parseLong(tokens[0]),
                    Long.parseLong(tokens[1])
            ));
        }

        while (!pq.isEmpty()) {
            Meeting curr = pq.poll();

            int minIndex = -1;
            long minValue = INF;
            for (int i = 0; i < K; i++) {
                if (room[i].getEndTime() < curr.getStartTime() && curr.getStartTime() - room[i].getEndTime() < minValue) {
                    minIndex = i;
                    minValue = curr.getStartTime() - room[i].getEndTime();
                }
            }

            if (minIndex != -1) {
                room[minIndex] = curr;
                count++;
            }
        }

        bw.write(Integer.valueOf(count).toString());
        bw.flush();
        bw.close();
    }

    static class Meeting implements Comparable<Meeting> {
        private Long startTime;
        private Long endTime;

        public Meeting(Long startTime, Long endTime) {
            this.startTime = startTime;
            this.endTime = endTime;
        }

        public Long getStartTime() {
            return startTime;
        }

        public Long getEndTime() {
            return endTime;
        }

        @Override
        public int compareTo(Meeting other) {
            if (endTime.equals(other.getEndTime())) {
                return startTime.compareTo(other.getStartTime());
            }
            return endTime.compareTo(other.getEndTime());
        }
    }
}
