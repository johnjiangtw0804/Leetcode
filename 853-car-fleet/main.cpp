#include <iostream>
#include <vector>

using namespace std;
using PII = pair<int,int>;

class Solution{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();
        if (n == 1 || n == 0) {
            return n;
        }
        vector<PII> positionWithSpeed;
        for (int i = 0; i < n; i++) {
            positionWithSpeed.push_back(PII(position[i], speed[i]));
        }
        sort(positionWithSpeed.begin(), positionWithSpeed.end());
        vector<double> stepsToTarget;

        for (PII& pos2Speed : positionWithSpeed) {
            double step = (target - pos2Speed.first)/ (1.0 *pos2Speed.second);
            stepsToTarget.push_back(step);
        }

        vector<int> prevGreater(n, -1); // we are the greatest
        // 2 (3 - 4) car fleet
        stack<int> decreasingStack;
        for (int i = 0; i < n; i++) {
            // 5 2 4()
            while (decreasingStack.size() > 0 && (stepsToTarget[decreasingStack.top()]) <= stepsToTarget[i]) {
                decreasingStack.pop();
            }
            // > then i
            if (decreasingStack.size() > 0) {
                prevGreater[i] = decreasingStack.top();
            }
            decreasingStack.push(i);
        }
        int fleetCount = 0;
        int fleetLeaderIdx = n - 1;
        while (fleetLeaderIdx >= 0) {
            fleetCount++;
            int prevGreaterIdx = prevGreater[fleetLeaderIdx];
            fleetLeaderIdx = prevGreaterIdx;
        }
        return fleetCount;
    }
};

int main (int argc, char** argv) {
    // target = 12, position = [ 10, 8, 0, 5, 3 ], speed = [ 2, 4, 1, 1, 3 ]
    // [0 3 5 8 10] [1, 3, 1, 4 , 2]
    // 12, (3, 7), (1, 1)
    // everything before the current car that can reach the tareget with shorter steps => form a car fleet
    // prev greater

    // n = 10^5
    Solution s;
    vector<int> position = {3, 4, 5, 6, 7, 8};
    vector<int> speed = {4, 4, 4, 4, 4, 4};
    int fleetsCount = s.carFleet(10, position, speed);
    cout << ((fleetsCount == 6) ? "true" : "false: fleet count = " + to_string(fleetsCount)) << endl;
    // 10 (6 8) (3 2)
    vector<int> position2 = {6, 8};
    vector<int> speed2 = {3,2};
    fleetsCount = s.carFleet(10, position2, speed2);
    cout << ((fleetsCount == 2) ? "true" : "false: fleet count = " + to_string(fleetsCount)) << endl;
}
