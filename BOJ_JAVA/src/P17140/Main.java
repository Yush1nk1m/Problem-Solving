package P17140;

import java.io.*;
import java.util.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair other) {
            if (this.first == other.first)
                return this.second - other.second;
            return this.first - other.first;
        }
    }

    static class Table {
        int[][] status = new int[101][101];
        int r, c;

        public Table() {
            r = 3;
            c = 3;
        }

        public void initialize() throws IOException {
            for (int r = 1; r <= 3; r++) {
                tokens = br.readLine().split(" ");
                for (int c = 1; c <= 3; c++)
                    status[r][c] = Integer.parseInt(tokens[c - 1]);
            }
        }

        public int get(int r, int c) {
            return status[r][c];
        }

        public void arrange() {
            int nr = 0, nc = 0;
            if (r >= c) {
                for (int i = 1; i <= r; i++) {
                    Map<Integer, Integer> map = new HashMap<>();
                    List<Pair> list = new ArrayList<>();

                    for (int j = 1; j <= c; j++)
                        if (status[i][j] != 0)
                            map.put(status[i][j], map.getOrDefault(status[i][j], 0) + 1);

                    for (int key : map.keySet())
                        list.add(new Pair(map.get(key), key));

                    Collections.sort(list);
                    Arrays.fill(status[i], 0);

                    for (int j = 1; j < Math.min(list.size() * 2, 100); j += 2) {
                        status[i][j] = list.get(j / 2).second;
                        status[i][j + 1] = list.get(j / 2).first;
                    }

                    nc = Math.max(nc, Math.min(list.size() * 2, 100));
                }
                c = nc;
            } else {
                for (int j = 1; j <= c; j++) {
                    Map<Integer, Integer> map = new HashMap<>();
                    List<Pair> list = new ArrayList<>();

                    for (int i = 1; i <= r; i++)
                         if (status[i][j] != 0)
                             map.put(status[i][j], map.getOrDefault(status[i][j], 0) + 1);

                    for (int key : map.keySet())
                        list.add(new Pair(map.get(key), key));

                    Collections.sort(list);
                    for (int i = 1; i <= 100; i++)
                        status[i][j] = 0;

                    for (int i = 1; i < Math.min(list.size() * 2, 100); i += 2) {
                        status[i][j] = list.get(i / 2).second;
                        status[i + 1][j] = list.get(i / 2).first;
                    }

                    nr = Math.max(nr, Math.min(list.size() * 2, 100));
                }
                r = nr;
            }
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int r, c, k, sec;
    static Table table = new Table();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        r = Integer.parseInt(tokens[0]);
        c = Integer.parseInt(tokens[1]);
        k = Integer.parseInt(tokens[2]);
        table.initialize();

        while (table.get(r, c) != k) {
            ++sec;
            if (sec > 100)
                break;
            table.arrange();
        }

        if (sec <= 100)
            System.out.println(sec);
        else
            System.out.println(-1);
    }
}
