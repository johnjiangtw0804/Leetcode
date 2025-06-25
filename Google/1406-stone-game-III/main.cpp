#include <iostream>
using namespace std;
class Solution {
    public:
        string stoneGameIII(vector<int>& stoneValue) {
            // 1 <= stoneValue.length <= 5 * 104
            // [1,2,3,7,5,3,2,1,1]
            // [1 2 3]. when will someone stops taking the 3rd or second
            // minimize the other player's score
            // f

            return "";
    }
};

int main () {
    Solution s;
    vector<int> stoneValue = {1, 2, 3, 7 };
    string res = s.stoneGameIII(stoneValue);
    cout << ((res == "Bob") ? "true" : ("false " + res))<< endl;
}
