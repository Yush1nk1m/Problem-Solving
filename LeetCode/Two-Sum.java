class Solution {

    Map<Integer, List<Integer>> map = new HashMap<>();

    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; ++i) {
            map.putIfAbsent(nums[i], new ArrayList<>());
            map.get(nums[i]).add(i);
        }

        for (int i = 0; i < nums.length; ++i)
            if (map.containsKey(target - nums[i])) {
                int l = map.get(nums[i]).get(0);
                int r = map.get(target - nums[i]).get(map.get(target - nums[i]).size() - 1);
                if (l != r)
                    return new int[]{ l, r };
            }
        
        return new int[]{ 0, 0 };
    }
}
