package P3048;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static List<Ant> ants = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        String[] tokens = br.readLine().split(" ");

        int N1 = Integer.parseInt(tokens[0]);
        int N2 = Integer.parseInt(tokens[1]);

        String line = br.readLine();
        for (int i = N1 - 1; i >= 0; i--) {
            ants.add(new Ant(line.charAt(i), Direction.RIGHT));
        }

        line = br.readLine();
        for (int i = 0; i < N2; i++) {
            ants.add(new Ant(line.charAt(i), Direction.LEFT));
        }

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            List<Integer> candidates = new ArrayList<>();
            for (int i = 0; i < N1 + N2 - 1; i++) {
                if (ants.get(i).getDirection() == Direction.RIGHT
                && ants.get(i + 1).getDirection() == Direction.LEFT) {
                    candidates.add(i);
                }
            }

            for (int index : candidates) {
                Ant temp = ants.get(index);
                ants.set(index, ants.get(index + 1));
                ants.set(index + 1, temp);
            }
        }

        for (Ant ant : ants) {
            bw.write(ant.getCharacter());
        }
        bw.flush();
    }

    public static class Ant {
        private char character;
        private Direction direction;

        public Ant(char character, Direction direction) {
            this.character = character;
            this.direction = direction;
        }

        public char getCharacter() {
            return character;
        }

        public Direction getDirection() {
            return direction;
        }
    }

    public enum Direction {
        LEFT, RIGHT;
    }
}
