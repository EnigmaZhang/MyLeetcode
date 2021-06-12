#include <cstdlib>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) 
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode* pre = nullptr;
        ListNode* now = head;

        while (now)
        {
            if (now->val == val)
            {
                break;
            }
            else
            {
                pre = now;
                now = now->next;
            }
        }

        if (now)
        {
            if (!pre)
            {
                return now->next;
            }
            else
            {
                pre->next = now->next;
                return head;
            }
        }

        return head;
    }
};