class Solution {

    int height, index;
    int[] tree, ret;

    public int[] maxSlidingWindow(int[] nums, int k) {
        height = (int) Math.ceil(Math.log(nums.length) / Math.log(2)) + 1;
        tree = new int[1 << height];
        index = 1 << (height - 1);
        for (int i = 0; i < nums.length; ++i)
            tree[index + i] = nums[i];
        for (int i = index - 1; i > 0; --i)
            tree[i] = Math.max(tree[i << 1], tree[(i << 1) + 1]);
        
        ret = new int[nums.length - k + 1];
        for (int i = 0; i < ret.length; ++i)
            ret[i] = query(i, i + k - 1);
        
        return ret;
    }

    private int query(int from, int to) {
        int ret = -10001;
        from += index;
        to += index;
        while (from <= to) {
            if (from % 2 != 0)
                ret = Math.max(ret, tree[from]);
            if (to % 2 == 0)
                ret = Math.max(ret, tree[to]);
            from = (from + 1) >> 1;
            to = (to - 1) >> 1;
        }
        return ret;
    }
}
