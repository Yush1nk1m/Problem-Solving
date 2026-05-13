class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; ++i)
            for (int j = i + 1; j < nums.length; ++j)
                if (binarySearch(nums, -nums[i] - nums[j], j + 1, nums.length - 1)) {
                    boolean isValid = true;
                    for (List<Integer> list : result)
                        if (list.get(0) == nums[i] && list.get(1) == nums[j] && list.get(2) == -nums[i] - nums[j]) {
                            isValid = false;
                            break;
                        }
                    if (isValid)
                        result.add(new ArrayList(Arrays.asList(nums[i], nums[j], -nums[i] - nums[j])));
                }
        
        return result;
    }

    private boolean binarySearch(int[] array, int target, int l, int h) {
        while (l <= h) {
            int m = (l + h) >> 1;
            if (array[m] < target)
                l = m + 1;
            else if (array[m] > target)
                h = m - 1;
            else
                return true;
        }
        return false;
    }
}
