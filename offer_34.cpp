#include <iostream>
#include <vector>
#include <stack>


struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution 
{
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int target) 
    {
        std::vector<std::vector<int>> ret_val;
        std::vector<int> nowPath;

        treeNodeSum(root, target, 0, ret_val, nowPath);
        return ret_val;
    }

private:
    void treeNodeSum(TreeNode* node, int target, int now_value, std::vector<std::vector<int>>& ret_val, std::vector<int>& nowPath)
    {
        if (node != nullptr)
        {
            now_value += node->val;
            nowPath.push_back(node->val);
            if (node->left == nullptr && node->right == nullptr && target == now_value)
            {
                ret_val.push_back(std::vector(nowPath));
                nowPath.pop_back();
                return;
            }
            if (node->left != nullptr)
            {
                treeNodeSum(node->left, target, now_value, ret_val, nowPath);
            }

            if (node->right != nullptr)
            {
                treeNodeSum(node->right, target, now_value, ret_val, nowPath);
            }
            
            nowPath.pop_back();
            return;
        }
        else
        {
            return;
        }

    }
};

int main()
{
    Solution solution = Solution();

    return 0;
}