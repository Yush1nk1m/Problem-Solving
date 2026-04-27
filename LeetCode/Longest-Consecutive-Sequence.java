class Solution {

    Set<Integer> set = new HashSet<>();

    public int longestConsecutive(int[] nums) {
        int size = 0;

        for (int num : nums)
            set.add(num);

        for (int num : nums)
            if (set.contains(num)) {
                int low = num - 1, high = num + 1;
                while (set.contains(low))
                    --low;
                ++low;
                while (set.contains(high))
                    ++high;
                --high;

                size = Math.max(size, high - low + 1);
                for (int i = low; i <= high; ++i)
                    set.remove(i);
            }

        return size;
    }
}
