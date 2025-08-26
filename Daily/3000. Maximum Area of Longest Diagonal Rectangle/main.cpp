#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        vector<vector<double>> res_set;
        for (vector<int> dimension : dimensions)
        {
            int l = dimension.at(0);
            int w = dimension.at(1);

            res_set.push_back({l * l + w * w * 1.0, l * 1.0 * w});
        }
        auto comp = [](const vector<double> &a, const vector<double> &b)
        {
            if (a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        };
        sort(res_set.begin(), res_set.end(), comp);

        return res_set.at(0)[1];
    }
};
