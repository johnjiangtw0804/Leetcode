#include <vector>
#include<algorithm>
#include<unordered_set>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        // we are trying to get the top level file directories
        auto comp = [](const string &a, const string &b)
        {
            if (a.size() != b.size())
                return a.size() < b.size();
            return a < b; // only if length equal
        };
        sort(folder.begin(), folder.end(), comp);
        vector<string> res;
        unordered_set<string> seen;
        for (int i = 0; i < (int)folder.size(); i++)
        {
            string f = folder[i];
            string build;
            ;
            stringstream ss(f);
            bool isSub = false;
            string dir;
            while (getline(ss, dir, '/'))
            {
                build.append(dir);
                if (seen.contains(build))
                {
                    isSub = true;
                    break;
                }
                build.append("/");
            }
            if (!isSub)
            {
                res.push_back(f);
                seen.insert(f);
            }
        }

        return res;
    }
};
