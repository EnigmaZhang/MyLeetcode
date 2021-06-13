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

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if (A == nullptr || B == nullptr)
        {
            return false;
        }

        if (A->val == B->val)
        {
            return doesHaveTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
        }
        else
        {
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);
        }
    }

    bool doesHaveTree(TreeNode* A, TreeNode* B)
    {
        if (B == nullptr)
        {
            return true;
        }
        else if (A == nullptr)
        {
            return false;
        }
        else
        {
            if (A->val == B->val)
            {
                return doesHaveTree(A->left, B->left) && doesHaveTree(A->right, B->right);
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{
    Solution solution = Solution();


    return 0;
}