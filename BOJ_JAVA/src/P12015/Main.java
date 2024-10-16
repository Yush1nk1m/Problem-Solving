package P12015;

import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        LIS lis = new LIS(N);
        String[] elements = br.readLine().split(" ");

        for (String element : elements) {
            Integer parsedElement = Integer.parseInt(element);
            int index = lis.lowerBound(parsedElement);
            lis.appendSequence(index, parsedElement);
        }

        bw.write(lis.getLength().toString());
        bw.flush();
        bw.close();
    }

    static class LIS {
        private List<Integer> sequence;

        public LIS(int capacity) {
            sequence = new ArrayList<>(capacity + 1);
            sequence.add(0);
        }

        public int lowerBound(Integer target) {
            int s = 0, e = sequence.size();
            while (s < e) {
                int mid = (s + e) / 2;

                if (sequence.get(mid) >= target) {
                    e = mid;
                } else {
                    s = mid + 1;
                }
            }
            return e;
        }

        public void appendSequence(int index, Integer value) {
            if (index == sequence.size()) {
                sequence.add(value);
            } else {
                sequence.set(index, Math.min(sequence.get(index), value));
            }
        }

        public Integer getLength() {
            return sequence.size() - 1;
        }
    }
}
