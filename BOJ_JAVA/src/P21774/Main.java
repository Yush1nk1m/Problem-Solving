package P21774;

import java.io.*;
import java.util.*;
import java.time.*;

public class Main {

    static class Log implements Comparable<Log> {
        LocalDateTime dt;
        int level;

        public Log(LocalDateTime dt, int level) {
            this.dt = dt;
            this.level = level;
        }

        public int compareTo(Log other) {
            return dt.compareTo(other.dt);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N, Q;
    static Log[] logs;
    static int[][] count = new int[7][];

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        Q = Integer.parseInt(tokens[1]);

        logs = new Log[N + 1];
        for (int i = 1; i <= 6; ++i)
            count[i] = new int[N + 1];
        logs[0] = new Log(LocalDateTime.of(1999, 12, 31, 0, 0, 0), 1);
        for (int i = 1; i <= N; ++i) {
            tokens = br.readLine().split("#");
            logs[i] = new Log(
                    parseLine(tokens[0]),
                    Integer.parseInt(tokens[1])
            );
        }
        Arrays.sort(logs);
        for (int i = 1; i <= N; ++i) {
            ++count[logs[i].level][i];
            for (int l = 1; l <= 6; ++l)
                count[l][i] += count[l][i - 1];
        }

        while (Q-- > 0) {
            tokens = br.readLine().split("#");
            int low = later(parseLine(tokens[0]));
            int high = sooner(parseLine(tokens[1]));
            int level = Integer.parseInt(tokens[2]);
            if (low == 0 || high == N + 1 || low > high)
                sb.append("0\n");
            else {
                int total  = 0;
                while (level <= 6) {
                    total += count[level][high] - count[level][low - 1];
                    ++level;
                }
                sb.append(total).append('\n');
            }
        }

        System.out.print(sb);
    }

    public static LocalDateTime parseLine(String line) {
        String[] tokens = line.split(" ");
        String[] date = tokens[0].split("-");
        String[] time = tokens[1].split(":");

        int year = Integer.parseInt(date[0]);
        int month = Integer.parseInt(date[1]);
        int day = Integer.parseInt(date[2]);
        int hour = Integer.parseInt(time[0]);
        int minute = Integer.parseInt(time[1]);
        int second = Integer.parseInt(time[2]);

        return LocalDateTime.of(year, month, day, hour, minute, second);
    }

    public static int later(LocalDateTime now) {
        int l = 1, h = N, ret = N + 1;

        while (l <= h) {
            int m = (l + h) >> 1;
            if (logs[m].dt.compareTo(now) < 0) {
                l = m + 1;
            } else {
                ret = Math.min(ret, m);
                h = m - 1;
            }
        }

        return ret;
    }

    public static int sooner(LocalDateTime now) {
        int l = 1, h = N, ret = 0;

        while (l <= h) {
            int m = (l + h) >> 1;
            if (logs[m].dt.compareTo(now) > 0) {
                h = m - 1;
            } else {
                ret = Math.max(ret, m);
                l = m + 1;
            }
        }

        return ret;
    }

}
