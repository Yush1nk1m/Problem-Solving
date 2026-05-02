class Solution {
    public int trap(int[] height) {
        int l = 0, r = 0, area = 0;
        while (l < height.length && r < height.length) {
            int h = 0;
            r = l + 1;
            while (r < height.length && height[l] > height[r]) {
                h = Math.max(h, Math.min(height[l], height[r]));
                ++r;
            } if (r < height.length) h = Math.max(h, Math.min(height[l], height[r]));
            while (l < r) {
                if (r < height.length && height[l] <= height[r])
                    area += Math.max(0, h - height[l]);
                ++l;
            }
        }
        r = height.length - 1;
        while (l >= 0 && r >= 0) {
            int h = 0;
            l = r - 1;
            while (l >= 0 && height[r] >= height[l]) {
                h = Math.max(h, Math.min(height[l], height[r]));
                --l;
            } if (l >= 0) h = Math.max(h, Math.min(height[l], height[r]));
            while (l < r) {
                if (l >= 0 && height[r] < height[l])
                    area += Math.max(0, h - height[r]);
                --r;
            }
        }
        return area;
    }
}
