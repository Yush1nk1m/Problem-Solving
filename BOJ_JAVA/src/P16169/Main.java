package P16169;

import java.io.*;
import java.util.*;

public class Main {
    static class Computer implements Comparable<Computer> {
        int index, clazz, cost, arrivalTime;

        public Computer(int index, int clazz, int cost) {
            this.index = index;
            this.clazz = clazz;
            this.cost = cost;
            this.arrivalTime = 0;
        }

        public int getOperatingCost() {
            return cost;
        }

        public int getTransferCost(Computer other) {
            return (int) Math.pow(index - other.index, 2);
        }

        public int getArrivalTime() {
            return arrivalTime;
        }

        public void setArrivalTime(int time) {
            arrivalTime = Math.max(arrivalTime, time);
        }

        public int compareTo(Computer other) {
            if (clazz == other.clazz)
                return index - other.index;
            return clazz - other.clazz;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, totalCost;
    static Computer[] cpt;
    static int[] cls;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        cpt = new Computer[N];
        cls = new int[N + 3];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int clazz = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            ++cls[clazz];
            cpt[i] = new Computer(i, clazz, cost);
        }
        Arrays.sort(cpt);
        for (int i = 1; i < cls.length; i++)
            cls[i] += cls[i - 1];
        for (int c = 1; cls[c - 1] != cls[c]; c++)
            for (int i = cls[c - 1]; i < cls[c]; i++) {
                totalCost = Math.max(totalCost, cpt[i].getArrivalTime() + cpt[i].getOperatingCost());
                for (int j = cls[c]; j < cls[c + 1]; j++)
                    cpt[j].setArrivalTime(cpt[i].getArrivalTime() + cpt[i].getOperatingCost() + cpt[i].getTransferCost(cpt[j]));
            }

        System.out.println(totalCost);
    }
}
