package P15237;

import java.io.*;
import java.util.*;

public class Main {

    static class Data implements Comparable<Data> {
        int number;
        private static int i = 0;
        static Map<Integer, Integer> frequency = new HashMap<>();
        static Map<Integer, Integer> id = new HashMap<>();

        public Data(int number) {
            this.number = number;
            frequency.put(number, frequency.getOrDefault(number, 0) + 1);
            id.put(number, id.getOrDefault(number, i++));
        }

        public int getNumber() {
            return number;
        }

        public int compareTo(Data other) {
            if (frequency.get(number) == frequency.get(other.number))
                return id.get(number) - id.get(other.number);
            return frequency.get(other.number) - frequency.get(number);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N, C;
    static Data[] array;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        array = new Data[N];
        for (int i = 0; i < N; i++)
            array[i] = new Data(Integer.parseInt(st.nextToken()));
        Arrays.sort(array);

        for (Data data : array) {
            bw.write(String.valueOf(data.getNumber()));
            bw.write(' ');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
