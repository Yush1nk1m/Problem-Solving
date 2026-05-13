/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {

    int size = 0;
    Map<Node, Integer> map = new HashMap<>();
    Node[] nodes;

    public Node copyRandomList(Node head) {
        Node curr = head;
        while (curr != null) {
            map.put(curr, size++);
            curr = curr.next;
        }

        nodes = new Node[size + 1];
        curr = head;
        for (int i = 0; i < size; ++i) {
            nodes[i] = new Node(curr.val);
            curr = curr.next;
        }

        curr = head;
        for (int i = 0; i < size; ++i) {
            nodes[i].next = nodes[i + 1];
            nodes[i].random = curr.random == null ? null : nodes[map.get(curr.random)];
            curr = curr.next;
        }

        return nodes[0];
    }
}
