class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0, price = prices[0];
        for (int i = 1; i < prices.length; ++i) {
            price = Math.min(price, prices[i]);
            profit = Math.max(profit, prices[i] - price);
        }
        return profit;
    }
}
