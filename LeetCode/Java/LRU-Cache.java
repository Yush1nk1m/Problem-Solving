class LRUCache {

    class Node {
        int key, value;
        Node prev, next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    int capacity;
    Node head, tail;
    Map<Integer, Node> map = new HashMap<>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (!map.containsKey(key))
            return -1;
        
        Node node = map.get(key);
        if (tail != node) {
            if (node == head) {
                head = head.next;
                head.prev = null;
            } else {
                if (node.prev != null)
                    node.prev.next = node.next;
                if (node.next != null)
                    node.next.prev = node.prev;
            }
            tail.next = node;
            node.prev = tail;
            node.next = null;
            tail = node;
        }

        return map.get(key).value;
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            map.get(key).value = value;
            get(key);
            return;
        }

        Node node = new Node(key, value);
        map.put(key, node);
        if (tail == null) {
            head = tail = node;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = tail.next;
        }

        if (capacity > 0) {
            --capacity;
        } else {
            Node temp = head;
            head = head.next;
            head.prev = null;
            map.remove(temp.key);
        }
    }
}
