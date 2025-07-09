// a1 = 'xyz'
// b1 = '/home/a1'

// c1 = 'workstation'
// d1 = 'a1@c1:b1' 

// Output: Print the list of variable names and resulting value 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Resolver {
    public:
    void resolve(vector<string>& keys, vector<string>& values) {
        unordered_map<string, string> key2Val;
        unordered_map<string, int> key2Idx;
        unordered_map<string, unordered_set<string>> adj;
        int n = keys.size();
        vector<int> indegrees(n, 0);
        for (int i = 0; i < n; i++) {
            key2Val[keys[i]] = values[i];
            key2Idx[keys[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            string key = keys[i];
            string val = values[i];
            for (int pos = 0; pos < (int)val.size() - 1; pos++) {
                string sub = val.substr(pos, 2);
                if (key2Val.contains(sub)) {
                    indegrees[key2Idx[key]]++;
                    adj[sub].insert(key);
                    // b1: /a1
                    // a1 => b1
                }
            }
        }

        queue<string> q;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                q.push(keys[i]);
            }
        }
        while (q.size() > 0) {
            string currentKey = q.front(); q.pop();
            for (string neighborKey : adj[currentKey]) {
                indegrees[key2Idx[neighborKey]]--;
                int pos = 0;
                string& neighborValue = key2Val[neighborKey];
                while ((pos = neighborValue.find(currentKey, pos)) != string::npos)
                {
                    neighborValue.replace(pos, (currentKey.size()), key2Val[currentKey]);
                    pos += key2Val[currentKey].size();
                }
                if (indegrees[key2Idx[neighborKey]] == 0)
                {
                    q.push(neighborKey);
                }
            }
        }

        for (int i : indegrees) {
            if(i != 0) {
                cout << "cycle detected" << endl;
                return;
            }
        }
        for (auto [a,b] : key2Val) {
            cout << "key " << a << " val " << b << endl;
        }
    }
};

int main () {
    cout << "Test 1" << endl;
    vector<string> keys = {"a1", "b1", "c1", "d1"};
    vector<string> values = {"xyz", "/home/a1", "workstation", "a1@c1:b1"};
    Resolver r;
    r.resolve(keys, values);

    // cycle
    cout << "Test 2" << endl;
    vector<string> keys2 = {"a1", "b1"};
    vector<string> values2 = {"b1", "/a1"};
    r.resolve(keys2, values2);
}
