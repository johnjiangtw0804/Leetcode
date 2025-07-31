#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // ending at index i what are the possible or values
        unordered_set<int> curr;
        unordered_set<int> res;
        // every iteration we can at most set 32 bits
        for (int a : arr) {
            unordered_set<int> curr2;
            for (int b : curr) {
                curr2.insert(b | a);
            }
            curr2.insert(a);
            curr = std::move(curr2);
            res.insert(curr.begin(), curr.end());
        }
        return res.size();
    }
}
;
