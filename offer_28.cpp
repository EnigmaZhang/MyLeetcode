#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

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
    bool isSymmetric(TreeNode* root)
    {
        return isTwoTreeSymmetric(root, root);
    }
private:
    bool isTwoTreeSymmetric(TreeNode* a, TreeNode* b)
    {
        if (a == nullptr && b == nullptr)
        {
            return true;
        }

        if (a == nullptr || b == nullptr)
        {
            return false;
        }

        if (a->val == b->val)
        {
            return isTwoTreeSymmetric(a->left, b->right) && isTwoTreeSymmetric(a->right, b->left);
        }
        else
        {
            return false;
        }

    }
};

int main()
{
    Solution solution = Solution();


    return 0;
}