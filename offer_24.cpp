#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {};

};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (!head)
        {
            return head;
        }
        ListNode* now{ head };
        ListNode* pre{ nullptr };
        ListNode* next{ now->next };

        while (next)
        {
            now->next = pre;
            pre = now;
            now = next;
            next = next->next;
        }

        now->next = pre;
        return now;
    }
};

int main()
{
    Solution solution = Solution();


    return 0;
}