package P25376;

import java.io.*;
import java.util.*;

public class Main {

    static class State {
        static int[] effected = new int[20];
        int mask, size;

        public State(int mask, int size) {
            this.mask = mask;
            this.size = size;
        }

        public void setEffected(int i, int mask) {
            effected[i] = mask;
        }

        public int getMask() {
            return mask;
        }

        public List<State> getNextStates() {
            List<State> states = new ArrayList<>();
            for (int i = 0; i < size; i++)
                if ((mask & (1 << i)) == 0)
                    states.add(new State(mask ^ effected[i], size));
            return states;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, mask;
    static State state;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            if (st.nextToken().equals("1"))
                mask |= (1 << i);
        state = new State(mask, N);
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());
            mask = (1 << i);
            for (int j = 0; j < count; j++)
                mask |= (1 << (Integer.parseInt(st.nextToken()) - 1));
            state.setEffected(i, mask);
        }

        System.out.println(solve());
    }

    public static int solve() {
        int distance = 0;
        boolean[] visited = new boolean[1 << N];
        Queue<State> queue = new LinkedList<>();

        visited[state.getMask()] = true;
        queue.offer(state);
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                State curr = queue.poll();
                if (curr.getMask() == (1 << N) - 1)
                    return distance;

                for (State next : curr.getNextStates())
                    if (!visited[next.getMask()]) {
                        visited[next.getMask()] = true;
                        queue.offer(next);
                    }
            }
            distance++;
        }

        return -1;
    }
}
