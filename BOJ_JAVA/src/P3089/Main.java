package P3089;

import java.io.*;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int N, M, X, Y, currX, currY;
    static String commands;
    static Map<Integer, List<Integer>> lineX = new HashMap<>();
    static Map<Integer, List<Integer>> lineY = new HashMap<>();

    public static void main(String[] args) throws IOException {
        tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            X = Integer.parseInt(tokens[0]);
            Y = Integer.parseInt(tokens[1]);
            if (!lineX.containsKey(X))
                lineX.put(X, new ArrayList<>());
            if (!lineY.containsKey(Y))
                lineY.put(Y, new ArrayList<>());
            lineX.get(X).add(Y);
            lineY.get(Y).add(X);
        }
        for (int key : lineX.keySet())
            Collections.sort(lineX.get(key));
        for (int key : lineY.keySet())
            Collections.sort(lineY.get(key));
        commands = br.readLine();
        for (char c : commands.toCharArray())
            switch (c) {
                case 'L':
                    currX = binarySearchLess(lineY.get(currY), currX);
                    break;
                case 'R':
                    currX = binarySearchGreater(lineY.get(currY), currX);
                    break;
                case 'U':
                    currY = binarySearchGreater(lineX.get(currX), currY);
                    break;
                case 'D':
                    currY = binarySearchLess(lineX.get(currX), currY);
                    break;
            }
        System.out.println(currX + " " + currY);
    }

    public static int binarySearchGreater(List<Integer> list, int target) {
        int l = 0, r = list.size() - 1, ret = Integer.MAX_VALUE;
        while (l <= r) {
            int m = (l + r) / 2;
            if (list.get(m) > target) {
                ret = Math.min(ret, list.get(m));
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }

    public static int binarySearchLess(List<Integer> list, int target) {
        int l = 0, r = list.size() - 1, ret = Integer.MIN_VALUE;
        while (l <= r) {
            int m = (l + r) / 2;
            if (list.get(m) < target) {
                ret = Math.max(ret, list.get(m));
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ret;
    }
}
