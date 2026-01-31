package P14718;

import java.io.*;
import java.util.*;

public class Main {

    static class Status {
        int strength, dexterity, intelligence;

        public Status(int strength, int dexterity, int intelligence) {
            this.strength = strength;
            this.dexterity = dexterity;
            this.intelligence = intelligence;
        }

        public boolean winnable(Status other) {
            return strength >= other.strength && dexterity >= other.dexterity && intelligence >= other.intelligence;
        }

        public int sum() {
            return strength + dexterity + intelligence;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, K, total = 3_000_000;
    static Status[] stats = new Status[100];

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        K = Integer.parseInt(tokens[1]);
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            stats[i] = new Status(
                    Integer.parseInt(tokens[0]),
                    Integer.parseInt(tokens[1]),
                    Integer.parseInt(tokens[2])
            );
        }
        for (int s = 0; s < N; ++s)
            for (int d = 0; d < N; ++d)
                for (int i = 0; i < N; ++i) {
                    Status status = new Status(stats[s].strength, stats[d].dexterity, stats[i].intelligence);
                    int count = 0;
                    for (int j = 0; j < N; ++j) {
                        if (status.winnable(stats[j]))
                            ++count;
                    }
                    if (count >= K)
                        total = Math.min(total, status.sum());
                }
        System.out.print(total);
    }

}
