import java.util.*;
class LRUCache {
    private class Node {
        int key;
        int value;
        Node next;
        Node prev;
        Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.next = null;
            this.prev = null;
        }
    }
    private int size = 0;
    private int capacity;

    private Node head;
    private Node tail;
    private HashMap<Integer, Node> key2Node;
    public LRUCache(int capacity) {
        this.capacity = capacity;

        key2Node = new HashMap<>();
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (!key2Node.containsKey(key)) {
            return -1;
        }
        // get the node and move the order
        Node ret = key2Node.get(key);
        removeNode(ret);
        addNode(ret);
        return ret.value;
    }

    // List ops
    private void removeNode(Node rem) {
        Node prev = rem.prev;
        Node next = rem.next;
        prev.next = next;
        next.prev = prev;
    }
    private void addNode(Node newNode) {
        Node next = head.next;
        newNode.prev = head;
        newNode.next = next;
        next.prev = newNode;
        head.next = newNode;
    }
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (key2Node.containsKey(key)) {
            Node oldNode = key2Node.get(key);
            oldNode.value = value;
            removeNode(oldNode);
            addNode(oldNode);
            return;
        }
        if (size == capacity) {
            key2Node.remove(tail.prev.key);
            removeNode(tail.prev);
            size--;
        }
        Node newNode = new Node(key, value);
        addNode(newNode);
        key2Node.put(key, newNode);
        size++;
    }

    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(2);

        // 2,2
        lRUCache.put(2, 2);
        // 3,3 2,2
        lRUCache.put(3,3);
        // 2,4, 3,3
        lRUCache.put(2,4);
        // System.out.println(lRUCache.get(2));
        System.out.println(lRUCache.get(2) == 4 ? "TRUE" : "FALSE");

        // 5,5, 2,4
        lRUCache.put(5,5);
        System.out.println(lRUCache.get(3) == -1 ? "TRUE" : "FALSE");
    }
}
