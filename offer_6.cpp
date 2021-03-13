class Solution {
public:
    std::vector<int> reversePrint(ListNode* head) 
    {
        std::vector<int> result;

        while (head != NULL)
        {
            result.push_back(head->val);
            head = head->next;
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};