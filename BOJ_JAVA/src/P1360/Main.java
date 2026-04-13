package P1360;

import java.io.*;

public class Main {

    static class Node {
        String type;
        int field1, field2;
        boolean valid;

        public Node(String type, int field1, int field2) {
            this.type = type;
            this.field1 = field1;
            this.field2 = field2;
            this.valid = true;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;
    static StringBuilder sb = new StringBuilder();

    static int N;
    static Node[] list;

    public static void main(String[] args) throws IOException {
        initialize();
        solve();
    }

    private static void initialize() throws IOException {
        N = Integer.parseInt(br.readLine());
        list = new Node[N];
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            list[i] = new Node(
                    tokens[0],
                    tokens[0].equals("type") ? (int) tokens[1].charAt(0) : Integer.parseInt(tokens[1]),
                    Integer.parseInt(tokens[2])
            );
        }
    }

    private static void solve() {
        for (int i = N - 1; i >= 0; --i) {
            if (list[i].type.equals("undo") && list[i].valid) {
                int j = i - 1;
                while (j >= 0 && list[j].field2 >= list[i].field2 - list[i].field1) {
                    list[j].valid = !list[j].valid;
                    --j;
                }
            }
        }

        for (int i = 0; i < N; ++i)
            if (list[i].type.equals("type") && list[i].valid)
                sb.append((char) list[i].field1);

        System.out.print(sb);
    }
}
