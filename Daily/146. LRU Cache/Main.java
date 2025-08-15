import java.util.*;

class LRUCache {
    private static class Node {
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
    private final int capacity;

    private Node head;
    private Node tail;
    private Map<Integer, Node> key2Node;

    public LRUCache(int capacity) {
        this.capacity = capacity;

        key2Node = new HashMap<>();
        head = new Node(-1, -1);
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
        removeBack(ret);
        addFront(ret);
        return ret.value;
    }

    // List ops
    private void removeBack(Node rem) {
        Node prev = rem.prev;
        Node next = rem.next;
        prev.next = next;
        next.prev = prev;
    }

    private void addFront(Node newNode) {
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
            removeBack(oldNode);
            addFront(oldNode);
            return;
        }
        if (size == capacity) {
            key2Node.remove(tail.prev.key);
            removeBack(tail.prev);
            size--;
        }
        Node newNode = new Node(key, value);
        addFront(newNode);
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
