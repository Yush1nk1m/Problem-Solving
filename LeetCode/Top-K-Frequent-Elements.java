class Solution {

    int[] count = new int[2001];
    Map<Integer, Set<Integer>> map = new HashMap<>();
    List<Integer> list = new ArrayList<>();

    public int[] topKFrequent(int[] nums, int k) {
        for (int num : nums)
            ++count[num + 1000];    
        for (int num : nums) {
            map.putIfAbsent(count[num + 1000], new HashSet<>());
            map.get(count[num + 1000]).add(num);
        }

        int frequency = nums.length;
        while (k > list.size()) {
            if (map.containsKey(frequency))
                list.addAll(map.get(frequency));
            --frequency;
        }

        int[] ret = new int[list.size()];
        for (int i = 0; i < ret.length; ++i)
            ret[i] = list.get(i);
        return ret;
    }
}
