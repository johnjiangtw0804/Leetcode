#include <iostream>
#include <list>

using namespace std;
using Node = pair<int,int>;

// struct Node{
//     int value;
//     int index;
// };

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<Node>::iterator> key2Node;
    list<Node> list;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (key2Node.find(key) == key2Node.end()) {
            return -1;
        }

        auto retNode = key2Node[key];
        // update the ordering
        list.splice(list.end(), list, retNode);
        return (*retNode).second;
    }
    void put(int key, int value) {
        if (key2Node.find(key) != key2Node.end()) {
            (*key2Node[key]).second = value;
            list.splice(list.end(), list, key2Node[key]);
            return;
        }
        // if it is not in the key cache
        if (this->capacity == key2Node.size()) {
            Node back = list.front();
            list.pop_front();
            key2Node.erase(back.first);
        }
        list.emplace(list.end(), Node(key, value));
        key2Node[key] = --list.end();
    }
};

int main () {
    // put() and get() with single
    LRUCache cache(2);
    cache.put(1, 1);
    cout << ((cache.get(1) == 1) ? "Correct" : ("False " + to_string(cache.get(1)))) << endl;
    cout <<((cache.get(2) == -1) ? "Correct" : "False") << endl;

    // 1
    // 1 2
    cache.put(2, 1);
    cout << ((cache.get(2) == 1) ? "Correct" : "False") << endl;

    // 2 3
    cache.put(3, 1);
    cout << ((cache.get(2) == 1) ? "Correct" : ("False" + to_string((cache.get(2))))) << endl;
    cout << ((cache.get(1) == -1) ? "Correct" : ("False " + to_string(cache.get(1)))) << endl;
    // 2 3
}
