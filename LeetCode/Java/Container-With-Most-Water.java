class Solution {
    public int maxArea(int[] heights) {
        int width = heights.length - 1, l = 0, r = heights.length - 1, maxArea = 0;
        while (l < r) {
            maxArea = Math.max(maxArea, width * Math.min(heights[l], heights[r]));
            if (heights[l] < heights[r])
                ++l;
            else
                --r;
            --width;
        }
        return maxArea;
    }
}
