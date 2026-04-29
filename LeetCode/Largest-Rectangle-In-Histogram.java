class Solution {

    class Node {
        int index, height;

        public Node(int index, int height) {
            this.index = index;
            this.height = height;
        }
    }

    Stack<Node> stack = new Stack<>();

    public int largestRectangleArea(int[] heights) {
        int area = 0;

        for (int i = 0; i < heights.length; ++i) {
            Node curr = new Node(i, heights[i]);
            while (!stack.isEmpty() && stack.peek().height > heights[i]) {
                Node node = stack.pop();
                area = Math.max(area, node.height * (i - node.index));
                curr.index = node.index;
            }
            stack.push(curr);
        }

        while (!stack.isEmpty()) {
            Node node = stack.pop();
            area = Math.max(area, node.height * (heights.length - node.index));
        }

        return area;
    }
}
