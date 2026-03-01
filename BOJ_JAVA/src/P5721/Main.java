    package P5721;

    import java.io.*;

    public class Main {

        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static String[] tokens;
        static StringBuilder sb = new StringBuilder();

        static int M, N;
        static int[] row, col;

        public static void main(String[] args) throws IOException {
            while (initialize())
                sb.append(solve()).append('\n');
            System.out.print(sb);
        }

        public static boolean initialize() throws IOException {
            tokens = br.readLine().split(" ");
            M = Integer.parseInt(tokens[0]);
            N = Integer.parseInt(tokens[1]);
            if (M == 0 || N == 0)
                return false;

            row = new int[M + 1];
            col = new int[N + 1];
            for (int r = 1; r <= M; ++r) {
                tokens = br.readLine().split(" ");
                for (int c = 1; c <= N; ++c)
                    col[c] = Integer.parseInt(tokens[c - 1]);
                row[r] = findMaxSum(col);
            }

            return true;
        }

        public static int solve() {
            return findMaxSum(row);
        }

        public static int findMaxSum(int[] array) {
            for (int i = 2; i < array.length; ++i)
                array[i] = Math.max(array[i] + array[i - 2], array[i - 1]);

            return array[array.length - 1];
        }
    }
