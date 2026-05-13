class Solution {
    
    Set<Integer> set = new HashSet<>();

    public boolean hasDuplicate(int[] nums) {
        for (int num : nums) {
            if (set.contains(num))
                return true;
            set.add(num);
        }
        return false;
    }
}