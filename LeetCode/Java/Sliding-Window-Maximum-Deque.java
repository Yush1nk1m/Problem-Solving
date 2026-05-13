class Solution {

    class Node {
        int index, value;

        public Node(int index, int value) {
            this.index = index;
            this.value = value;
        }

        public String toString() {
            return "(i: " + index + ", v: " + value + ")";
        }
    }

    int[] ret;
    Deque<Node> deque = new ArrayDeque<>();    

    public int[] maxSlidingWindow(int[] nums, int k) {
        ret = new int[nums.length - k + 1];
        for (int i = 0; i < k - 1; ++i) {
            while (!deque.isEmpty() && deque.peekLast().value < nums[i])
                deque.pollLast();
            deque.offerLast(new Node(i, nums[i]));
        }
        for (int i = k - 1; i < nums.length; ++i) {
            while (!deque.isEmpty() && deque.peekFirst().index <= i - k)
                deque.pollFirst();
            while (!deque.isEmpty() && (deque.peekLast().index <= i - k || deque.peekLast().value < nums[i]))
                deque.pollLast();
            deque.offerLast(new Node(i, nums[i]));
            ret[i - k + 1] = deque.peekFirst().value;
        }
        return ret;
    }
}
