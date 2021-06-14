#include <iostream>


class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) : val(_val), next(NULL), random(NULL) {}
};

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if (!head)
        {
            return nullptr;
        }
        copyEachNode(head);
        setCopyRandom(head);
        return splitTwoLindedList(head);
    }
private:
    void copyEachNode(Node* head)
    {
        Node* nowNode{ head };

        while (nowNode)
        {
            Node* nowCopy = new Node(nowNode->val);
            nowCopy->next = nowNode->next;
            nowNode->next = nowCopy;
            nowNode = nowCopy->next;
        }
    }

    void setCopyRandom(Node* head)
    {
        Node* nowOriginNode{ head };
        while (nowOriginNode)
        {
            if (nowOriginNode->random != nullptr)
            {
                nowOriginNode->next->random = nowOriginNode->random->next;
            }
            else
            {
                nowOriginNode->next->random = nullptr;
            }
            nowOriginNode = nowOriginNode->next->next;
        }
    }

    Node* splitTwoLindedList(Node* head)
    {
        Node* nowNode{ head };
        Node* copyHead{ head->next };
        Node* copyNow{ head->next };

        while (nowNode->next->next)
        {
            Node* tmp{ nowNode->next->next };
            copyNow->next = copyNow->next->next;
            nowNode->next = tmp;
            copyNow = copyNow->next;
            nowNode = nowNode->next;
        }
        nowNode->next = nullptr;
        return copyHead;
    }
};



int main()
{
    Solution solution = Solution();

    return 0;
}