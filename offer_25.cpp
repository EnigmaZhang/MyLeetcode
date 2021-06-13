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

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode* newHead{ nullptr };

        if (l1->val > l2->val)
        {
            newHead = l2;
            l2 = l2->next;
        }
        else
        {
            newHead = l1;
            l1 = l1->next;
        }

        ListNode* newNow{ newHead };

        while (newNow)
        {
            if (l1 == nullptr)
            {
                newNow->next = l2;
                break;
            }
            if (l2 == nullptr)
            {
                newNow->next = l1;
                break;
            }

            if (l1->val > l2->val)
            {
                newNow->next = l2;
                l2 = l2->next;
                newNow = newNow->next;
            }
            else
            {
                newNow->next = l1;
                l1 = l1->next;
                newNow = newNow->next;
            }
        }

        return newHead;
        
    }
};