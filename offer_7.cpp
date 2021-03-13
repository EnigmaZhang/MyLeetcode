#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        return buildCore(preorder, inorder);
    }

private:
    TreeNode* buildCore(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        if (preorder.size() == 0)
        {
            return NULL;
        }

        if (preorder.size() == 1)
        {
            return  new TreeNode(preorder[0]);
        }
        
        int rootValue = preorder[0];
        int rootIndex = std::find(inorder.begin(), inorder.end(), rootValue) - inorder.begin();

        // std::cout << rootValue << " " << rootIndex << std::endl;

        std::vector<int> leftInorder (inorder.begin(), inorder.begin() + rootIndex);
        std::vector<int> rightInorder (inorder.begin() + rootIndex + 1, inorder.end());

        // std::cout << leftInorder.size() << " " << rightInorder.size() << std::endl;

        std::vector<int> leftPreorder (preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        std::vector<int> rightPreorder (preorder.begin() + leftInorder.size() + 1, preorder.end());

        // std::cout << leftPreorder.size() << " " << rightPreorder.size() << std::endl;

        int val = rootValue;
        TreeNode* left = buildCore(leftPreorder, leftInorder);
        TreeNode* right = buildCore(rightPreorder, rightInorder);

        TreeNode* retVal = new TreeNode(val);
        retVal->left = left;
        retVal->right = right;

        return retVal;
    }
};

int main()
{
    std::vector<int> testPreorder {3, 9, 20, 15, 7};

    std::vector<int> testInorder {9, 3, 15, 20, 7};

    Solution solution = Solution();
    
    TreeNode* tree = solution.buildTree(testPreorder, testInorder);

    return 0;
}
