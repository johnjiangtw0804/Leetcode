#include <vector>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int quantity = fruits[i];
            bool hasFound = false;
            for (int j = 0; j < n; j++) {
                if (baskets[j] >= quantity) {
                    baskets[j] = -1;
                    hasFound = true;
                    break;
                }
            }
            if (!hasFound) {
                res++;
            }
        }
        return res;
    }
};
