package P3135;

import java.io.*;
import java.util.*;

public class UserSolution {

    class Node {
        char value, count;
        Map<Character, Node> next = new HashMap<>();

        public Node(char value) {
            this.value = value;
            this.count = 0;
        }
    }

    Node root;

    public void init() {
        root = new Node((char) 0);
    }

    public void insert(int buffer_size, String buf) {
        Node curr = root;
        for (char c : buf.toCharArray()) {
            curr.next.putIfAbsent(c, new Node(c));
            curr = curr.next.get(c);
            ++curr.count;
        }
    }

    public int query(int buffer_size, String buf) {
        Node curr = root;
        for (char c : buf.toCharArray()) {
            if (!curr.next.containsKey(c))
                return 0;
            curr = curr.next.get(c);
        }
        return curr.count;
    }
}
