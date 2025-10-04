package P8980;

import java.io.*;
import java.util.*;

public class Main {

    static class Box implements Comparable<Box> {
        int src, dest, count;

        public Box(int src, int dest, int count) {
            this.src = src;
            this.dest = dest;
            this.count = count;
        }

        public int compareTo(Box other) {
            return dest - other.dest;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, C, M, src, dest, count, maxDelivery;
    static int[] capability;
    static Box[] boxes;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        capability = new int[N + 1];
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(br.readLine());
        boxes = new Box[M];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            src = Integer.parseInt(st.nextToken());
            dest = Integer.parseInt(st.nextToken());
            count = Integer.parseInt(st.nextToken());
            boxes[i] = new Box(src, dest, count);
        }
        Arrays.sort(boxes);
        for (Box box : boxes) {
            int bound = box.count;
            for (int i = box.src; i < box.dest; i++)
                bound = Math.min(bound, C - capability[i]);
            maxDelivery += bound;
            for (int i = box.src; i < box.dest; i++)
                capability[i] += bound;
        }
        System.out.println(maxDelivery);
    }
}
