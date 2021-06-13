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
    ListNode* getKthFromEnd(ListNode* head, int k)
    {
        if (k == 0 || head == nullptr)
        {
            return nullptr;
        }

        int firstPoint{ 0 }, secondPoint{ - k };
        ListNode* firstNode{ head }, * secondNode{ head };

        while (firstNode)
        {
            firstPoint++;
            secondPoint++;
            firstNode = firstNode->next;
            if (secondPoint > 0)
            {
                secondNode = secondNode->next;
            }
        }

        return secondNode;
    }
};

int main()
{
    Solution solution = Solution();


    return 0;
}