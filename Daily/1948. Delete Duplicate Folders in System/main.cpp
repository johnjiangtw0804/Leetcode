#include <iostream>
#include <vector>
#include <functional>
#include <map>
using namespace std;

class Solution
{
    struct TrieNode
    {
        string s;
        map<string, unique_ptr<TrieNode>> child;
        bool isRemoved = false;
        string structure;
        TrieNode(string s) : s(s) {}
    };

public:
    TrieNode root = TrieNode("/");
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        for (int i = 0; i < paths.size(); i++)
        {
            TrieNode *trav = &root;
            for (const string &p : paths[i])
            {
                if (!trav->child.contains(p))
                {
                    trav->child[p] = make_unique<TrieNode>(p);
                }
                trav = trav->child[p].get();
            }
        }
        // DFS to build the serialize the tree structure
        map<string, vector<TrieNode *>> structureMap;
        function<string(TrieNode *)> serialize = [&](TrieNode *node) -> string
        {
            if (node->child.size() == 0)
            {
                return node->s + "#";
            }
            string str;
            for (auto &[s, child] : node->child)
            {
                str.append(s).append(",");
                str.append(serialize(child.get()));
            }
            if (!str.empty())
            {
                structureMap[str].push_back(node);
            }
            return str + "#";
        };
        serialize(&root);

        for (auto &[structure, nodes] : structureMap)
        {
            if (nodes.size() > 1)
            {
                for (TrieNode *node : nodes)
                {
                    node->isRemoved = true;
                }
            }
        }

        vector<vector<string>> res;
        vector<string> current_path;
        function<void(TrieNode *, vector<string> &)> Collect = [&](TrieNode *node, vector<string> &current_path)
        {
            for (auto &[p, child] : node->child)
            {
                if (child->isRemoved)
                    continue;
                current_path.push_back(p);
                res.push_back(current_path);
                Collect(child.get(), current_path);
                current_path.pop_back();
            }
        };
        Collect(&root, current_path);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> paths = {
        {"a"}, {"c"}, {"a", "b"}, {"c", "b"}, {"a", "b", "x"}, {"c", "b", "x"}, {"a", "b", "x", "y"}, {"c", "b", "x", "y"}, {"a", "b", "x", "y", "z"}, {"c", "b", "x", "y", "z"}};

    auto result = sol.deleteDuplicateFolder(paths);
    for (const auto &path : result)
    {
        for (const auto &dir : path)
            cout << "/" << dir;
        cout << endl;
    }
}
