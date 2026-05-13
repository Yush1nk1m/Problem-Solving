class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ret = new int[nums.length];
        int[] numsRev = new int[nums.length];
        System.arraycopy(nums, 0, numsRev, 0, nums.length);
        for (int i = 1; i < nums.length; ++i) {
            nums[i] *= nums[i - 1];
            numsRev[numsRev.length - i - 1] *= numsRev[numsRev.length - i];
        }

        for (int i = 0; i < nums.length; ++i) {
            ret[i] = 1;
            if (i + 1 < nums.length)
                ret[i] *= numsRev[i + 1];
            if (i - 1 >= 0)
                ret[i] *= nums[i - 1];
        }

        return ret;
    }
}  
