package P27372;

import java.io.*;
import java.util.*;

public class Main {

    static class Coords {
        int r, c;

        public Coords(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int T;
    static String S, eval, minSeed;
    static char[][] table = new char[3][];
    static Map<Character, Coords> map = new HashMap<>();
    static char[] seed = new char[9];
    static boolean[] checked = new boolean[9];
    static boolean[][] visited = new boolean[3][3];

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            S = br.readLine();
            for (int r = 0; r < 3; ++r) {
                table[r] = br.readLine().toCharArray();
                for (int c = 0; c < 3; ++c)
                    map.put(table[r][c], new Coords(r, c));
            }
            eval = evaluate(S);
            findMinimumSeed();

            sb.append(eval).append(' ').append(minSeed).append('\n');
        }
        System.out.println(sb);
    }

    public static String evaluate(String seed) {
        char[] scores = new char[9];
        boolean[][] visited = new boolean[3][3];

        for (int ci = 0; ci < 9; ++ci) {
            Coords coords = map.get(seed.charAt(ci));
            int r = coords.r, c = coords.c, i;
            char score = '0';

            visited[r][c] = true;

            for (i = 0; i < 3; ++i)
                if (!visited[r][i])
                    break;
            if (i == 3)
                ++score;

            for (i = 0; i < 3; ++i)
                if (!visited[i][c])
                    break;
            if (i == 3)
                ++score;

            if ((r + c) % 2 == 0 && r == c) {
                for (i = 0; i < 3; ++i)
                    if (!visited[i][i])
                        break;
                if (i == 3)
                    ++score;
            }

            if ((r + c) % 2 == 0 && r == 2 - c) {
                for (i = 0; i < 3; ++i)
                    if (!visited[i][2 - i])
                        break;
                if (i == 3)
                    ++score;
            }

            scores[ci] = score;
        }

        return new String(scores);
    }

    public static char evaluate(char ch, boolean[][] visited) {
        Coords coords = map.get(ch);
        int r = coords.r, c = coords.c, i;
        char score = '0';

        visited[r][c] = true;

        for (i = 0; i < 3; ++i)
            if (!visited[r][i])
                break;

        if (i == 3)
            ++score;

        for (i = 0; i < 3; ++i)
            if (!visited[i][c])
                break;
        if (i == 3)
            ++score;

        if ((r + c) % 2 == 0 && r == c) {
            for (i = 0; i < 3; ++i)
                if (!visited[i][i])
                    break;
            if (i == 3)
                ++score;
        }

        if ((r + c) % 2 == 0 && r == 2 - c) {
            for (i = 0; i < 3; ++i)
                if (!visited[i][2 - i])
                    break;
            if (i == 3)
                ++score;
        }

        return score;
    }

    public static void findMinimumSeed() {
        minSeed = S;
        Arrays.fill(checked, false);
        for (boolean[] row : visited)
            Arrays.fill(row, false);
        permutation(0);
    }

    public static void permutation(int depth) {
        if (depth == 9) {
            String stringifiedSeed = new String(seed);
            if (stringifiedSeed.compareTo(minSeed) < 0)
                minSeed = stringifiedSeed;
            return;
        }

        for (int i = 0; i < 9; ++i)
            if (!checked[i]) {
                checked[i] = true;
                seed[depth] = S.charAt(i);
                char score = evaluate(S.charAt(i), visited);
                if (score == eval.charAt(depth))
                    permutation(depth + 1);
                unvisit(S.charAt(i), visited);
                checked[i] = false;
            }
    }

    public static void unvisit(char ch, boolean[][] visited) {
        Coords coords = map.get(ch);
        visited[coords.r][coords.c] = false;
    }
}
