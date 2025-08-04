#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // two types of fruits
        // greatest subarrays with two distinct ints
        unordered_map<int, int> freq;

        int start = 0;
        int end = 0;
        int res = 0;
        int n = fruits.size();
        while (end < n) {
            int type = fruits[end];
            freq[type]++;
            if (freq.size() > 2) {
                while (freq.size() > 2) {
                    freq[fruits[start]]--;
                    if (freq[fruits[start]] == 0) {
                        freq.erase(fruits[start]);
                    }
                    start++;
                }
            }
            res = max(res, end - start+1);
            end++;
        }
        return res;
    }
};
