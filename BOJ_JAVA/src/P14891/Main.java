package P14891;

import java.io.*;
import java.util.*;

public class Main {

    static class Wheel {
        static final int T = 0, R = 2, L = 6;
        static final char N = '0', S = '1';
        List<Character> state = new ArrayList<>();

        public Wheel(String expression) {
            for (char c : expression.toCharArray())
                state.add(c);
        }

        public List getState() {
            return state;
        }

        public void rotate(int dir) {
            Collections.rotate(state, dir);
        }
    }

    static class Board {
        List<Wheel> wheels = new ArrayList<>();
        boolean[] checked;
        Queue<Integer> queue = new LinkedList<>();

        public Board(int size) {
            checked = new boolean[size];
        }

        public void addWheel(String expression) {
            wheels.add(new Wheel(expression));
        }

        public void rotateWheel(int i, int dir) {
            --i;
            Arrays.fill(checked, false);

            queue.offer(i);
            checked[i] = true;
            while (!queue.isEmpty()) {
                int size = queue.size();
                while (size-- > 0) {
                    int curr = queue.poll();
                    if (curr + 1 < checked.length && !checked[curr + 1] &&
                            wheels.get(curr).getState().get(Wheel.R) != wheels.get(curr + 1).getState().get(Wheel.L)) {
                        checked[curr + 1] = true;
                        queue.offer(curr + 1);
                    }
                    if (curr - 1 >= 0 && !checked[curr - 1] &&
                            wheels.get(curr).getState().get(Wheel.L) != wheels.get(curr - 1).getState().get(Wheel.R)) {
                        checked[curr - 1] = true;
                        queue.offer(curr - 1);
                    }
                    wheels.get(curr).rotate(dir);
                }
                dir = -dir;
            }
        }

        public int getScore() {
            int score = 0;
            for (int i = 0; i < 4; i++)
                score += wheels.get(i).getState().get(Wheel.T).equals(Wheel.S) ? Math.pow(2, i) : 0;

            return score;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int K, n, dir;
    static Board board = new Board(4);

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 4; i++)
            board.addWheel(br.readLine());
        K = Integer.parseInt(br.readLine());
        while (K-- > 0) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            dir = Integer.parseInt(st.nextToken());
            board.rotateWheel(n, dir);
        }
        System.out.println(board.getScore());
    }
}
