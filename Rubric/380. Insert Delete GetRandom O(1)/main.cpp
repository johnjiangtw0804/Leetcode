#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class RandomizedSet {
private:
    unordered_map<int, int> dataStore;
    vector<int> keys;

public:
    RandomizedSet()
    {
        srand(time(NULL));
    }

    bool insert(int val)
    {
        if (dataStore.find(val) != dataStore.end()) {
            return false;
        }
        dataStore[val] = keys.size();
        keys.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (dataStore.find(val) == dataStore.end()) {
            return false;
        }

        // removing val at idx i
        // [1, 3] [0, 1]
        int i = dataStore[val];
        // [3,1] [1, 0]
        swap(keys[i], keys[(int)keys.size() - 1]);
        dataStore[keys[i]] = i;

        dataStore.erase(val);
        keys.pop_back();
        return true;
    }

    int getRandom()
    {
        int idx = rand() % (int)dataStore.size();
        int ret = keys[idx];
        return ret;
    }
};

int main() {
    RandomizedSet myRandomSet;
    cout << ((myRandomSet.insert(3) == true)? "Correct" : "false") << endl;
    cout << ((myRandomSet.getRandom() == 3) ? "Correct" : "false") << endl;
    cout << ((myRandomSet.remove(5) == false)? "Correct" : "false")<< endl;
    cout << ((myRandomSet.remove(3) == true) ? "Correct" : "false") << endl;
    cout << ((myRandomSet.insert(3) == true)? "Correct" : "false") << endl;

    cout << ((myRandomSet.insert(0) == true)? "Correct" : "false") << endl;
    cout << ((myRandomSet.remove(0) == true)? "Correct" : "false") << endl;
    cout << ((myRandomSet.insert(0) == true)? "Correct" : "false") << endl;
}
