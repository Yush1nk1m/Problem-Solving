class Solution {
    public int reverse(int x) {
        int t = Math.abs(x), y = 0;
        while (t > 0) {
            int p = y;
            y = y * 10 + (t % 10);
            if ((y - (t % 10)) / 10 != p)
                return 0;
            t /= 10;
        }
        return x > 0 ? y : -y;
    }
}