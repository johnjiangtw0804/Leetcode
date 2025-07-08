#include <vector>
#include <map>
#include <iostream>

using namespace std;
class SnapshotArray
{
private:
    vector<map<int, int>> snaps;
    int snapID = 0;

public:
    // 「用 map 只記必要版本，找歷史值時用 upper_bound 二分，就能避免 MLE。」
    SnapshotArray(int length)
    {
        snaps.resize(length);
        for (int i = 0; i < length; i++)
        {
            snaps[i][-1] = 0;
        }
    }

    void set(int index, int val)
    {
        snaps[index][snapID] = val;
    }

    int snap()
    {
        return snapID++;
    }

    int get(int index, int snap_id)
    {
        // upperbound >
        auto it = snaps[index].upper_bound(snap_id);
        return (--it)->second;
    }
};

int main() {
    SnapshotArray s(3);
    s.set(0, 5);
    s.snap();
    s.set(0, 6);
    int ret = s.get(0, 0);
    cout << ((ret == 5) ? "Correct " : "False " + to_string(ret)) << endl;
}
