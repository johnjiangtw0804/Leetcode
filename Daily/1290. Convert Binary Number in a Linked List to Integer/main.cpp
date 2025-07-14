#include <iostream>
using namespace std;

struct ListNode{
    int val;
    unique_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, unique_ptr<ListNode> next) : val(x), next(std::move(next)) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int res = 0;
        while(head != nullptr) {
            res = res * 2;
            if ((head->val & 1) == 1) {
                res +=1;
            }
            head = head->next.get();
        }
        return res;
    }
};


int main() {
    unique_ptr<ListNode> head = make_unique<ListNode>(1);
    head->next = make_unique<ListNode>(0);
    head->next->next = make_unique<ListNode>(1);
    Solution s;
    cout << s.getDecimalValue(head.get());
}

