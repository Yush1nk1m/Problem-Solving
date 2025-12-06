package P25391;

import java.io.*;
import java.util.*;

public class Main {

    static class Score {
        long host, judge;

        public Score(long host, long judge) {
            this.host = host;
            this.judge = judge;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, K;
    static long result;
    static List<Score> scores = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            scores.add(new Score(Long.parseLong(tokens[0]), Long.parseLong(tokens[1])));
        }
        scores.sort(new Comparator<Score>() {
            @Override
            public int compare(Score s1, Score s2) {
                if (s1.judge == s2.judge)
                    return Long.compare(s2.host, s1.host);
                return Long.compare(s1.judge, s2.judge);
            }
        });
        for (int i = 0; i < K; ++i) {
            result += scores.get(scores.size() - 1).host;
            scores.remove(scores.size() - 1);
        }
        scores.sort(new Comparator<Score>() {
            @Override
            public int compare(Score s1, Score s2) {
                return Long.compare(s1.host, s2.host);
            }
        });
        for (int i = 0; i < M; ++i) {
            result += scores.get(scores.size() - 1).host;
            scores.remove(scores.size() - 1);
        }
        System.out.println(result);
    }
}
