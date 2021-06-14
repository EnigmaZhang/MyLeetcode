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
    TreeNode* mirrorTree(TreeNode* root)
    {
        if (!root)
        {
            return root;
        }

        TreeNode* tmp;

        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);

        return root;
    }
};

int main()
{
    Solution solution = Solution();


    return 0;
}