package P1487;

import java.io.*;
import java.util.*;

class Main {

    static class Deal {
        int affordable, delivery;

        public Deal(int affordable, int delivery) {
            this.affordable = affordable;
            this.delivery = delivery;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] tokens;

    static int INF = -2_000_001;

    static int N, maxAffordable;
    static Deal[] deals;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        deals = new Deal[N];
        for (int i = 0; i < N; ++i) {
            tokens = br.readLine().split(" ");
            deals[i] = new Deal(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
            maxAffordable = Math.max(maxAffordable, deals[i].affordable);
        }
        System.out.println(solve());
    }

    public static int solve() {
        int benefit, maxBenefit = 0, maxPrice = 0;
        for (int price = 1; price <= maxAffordable; ++price) {
            benefit = calculate(price);
            if (maxBenefit < benefit) {
                maxBenefit = benefit;
                maxPrice = price;
            }
        }
        return maxPrice;
    }

    public static int calculate(int price) {
        int benefit = 0;
        for (Deal deal : deals)
            benefit += Math.max(0, (deal.affordable < price ? INF : price) - deal.delivery);
        return benefit;
    }
}
