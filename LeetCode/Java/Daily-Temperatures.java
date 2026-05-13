class Solution {

    Stack<Integer> stack = new Stack<>();

    public int[] dailyTemperatures(int[] temperatures) {
        int[] result = new int[temperatures.length];

        stack.push(0);
        for (int i = 1; i < temperatures.length; ++i) {
            while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
                result[stack.peek()] = i - stack.peek();
                stack.pop();
            }
            stack.push(i);
        }
        
        return result;
    }
}
