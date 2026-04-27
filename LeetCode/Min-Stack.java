class MinStack {

    class Node {
        int value, minimum;

        public Node(int value, int minimum) {
            this.value = value;
            this.minimum = minimum;
        }
    }

    Stack<Node> stack;

    public MinStack() {
        stack = new Stack<>();
    }
    
    public void push(int val) {
        if (stack.isEmpty())
            stack.push(new Node(val, val));
        else
            stack.push(new Node(val, Math.min(val, stack.peek().minimum)));
    }
    
    public void pop() {
        stack.pop();
    }
    
    public int top() {
        return stack.peek().value;
    }
    
    public int getMin() {
        return stack.peek().minimum;
    }
}
