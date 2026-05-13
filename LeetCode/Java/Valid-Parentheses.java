class Solution {

    Stack<Character> stack = new Stack<>();

    public boolean isValid(String s) {
        for (char c : s.toCharArray()) {
            if (c == ')') {
                if (stack.isEmpty() || stack.peek() != '(')
                    return false;
                stack.pop();
            } else if (c == '}') {
                if (stack.isEmpty() || stack.peek() != '{')
                    return false;
                stack.pop();
            } else if (c == ']') {
                if (stack.isEmpty() || stack.peek() != '[')
                    return false;
                stack.pop();
            } else stack.push(c);
        }
        return stack.isEmpty();
    }
}
