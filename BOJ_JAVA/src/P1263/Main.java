package P1263;

import java.io.*;
import java.util.*;

public class Main {

    static class Job implements Comparable<Job> {
        int duration, deadline;

        public Job(int duration, int deadline) {
            this.duration = duration;
            this.deadline = deadline;
        }

        public int compareTo(Job other) {
            return Integer.compare(deadline, other.deadline);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, duration, deadline, gap, time;
    static Job[] jobs;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        jobs = new Job[N];
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            jobs[i] = new Job(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
        }
        Arrays.sort(jobs);
        time = jobs[0].duration;
        gap = jobs[0].deadline - time;
        for (int i = 1; i < N; ++i) {
            time += jobs[i].duration;
            gap = Math.min(gap, jobs[i].deadline - time);
        }
        gap = Math.max(-1, gap);
        System.out.println(gap);
    }
}
