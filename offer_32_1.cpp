#include <iostream>
#include <deque>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    std::vector<int> levelOrder(TreeNode* root) 
    {
        std::vector<int> ret_val;
        std::deque<TreeNode*> q;

        if (root)
        {
            q.push_back(root);
            while (!q.empty())
            {
                ret_val.push_back(q.front()->val);
                if (q.front()->left)
                {
                    q.push_back(q.front()->left);
                }
                if (q.front()->right)
                {
                    q.push_back(q.front()->right);
                }
                q.pop_front();
            }
        }

        return ret_val;
    }
};

int main()
{
    Solution solution = Solution();

    return 0;
}