class Node implements Comparable<Node> {
    int value, index;
    
    public Node(int value, int index) {
        this.value = value;
        this.index = index;
    }

    public int compareTo(Node other) {
        return value - other.value;
    }

    public int getValue() {
        return value;
    }

    public int getIndex() {
        return index;
    }
}

class Solution {
    public int[] twoSum(int[] nums, int target) {
        List<Node> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++)
            list.add(new Node(nums[i], i));
        Collections.sort(list);

        int i = 0, j = nums.length - 1;
        while (i < j) {
            int sum = list.get(i).getValue() + list.get(j).getValue();
            if (sum > target)
                j--;
            else if (sum < target)
                i++;
            else
                break;
        }
        return new int[]{list.get(i).getIndex(), list.get(j).getIndex()};
    }
}