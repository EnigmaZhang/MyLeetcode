#include <iostream>
#include <deque>
#include <vector>
#include <stack>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {
        std::vector<std::vector<int>> ret_val;
        std::stack<TreeNode*> s1, s2;
        size_t level{ 0 };
        bool reverse = false;

        if (root)
        {
            s1.push(root);
            while (!s1.empty() || !s2.empty())
            {
                ret_val.push_back(std::vector<int>{});
                if (level % 2 == 0)
                {
                    size_t level_size{ s1.size() };
                    for (size_t i{ 0 }; i < level_size; i++)
                    {
                        ret_val[level].push_back(s1.top()->val);
                        if (s1.top()->left)
                        {
                            s2.push(s1.top()->left);
                        }
                        if (s1.top()->right)
                        {
                            s2.push(s1.top()->right);
                        }
                        s1.pop();
                    }
                }
                else
                {
                    size_t level_size{ s2.size() };
                    for (size_t i{ 0 }; i < level_size; i++)
                    {
                        ret_val[level].push_back(s2.top()->val);
                        if (s2.top()->right)
                        {
                            s1.push(s2.top()->right);
                        }
                        if (s2.top()->left)
                        {
                            s1.push(s2.top()->left);
                        }
                        s2.pop();
                    }
                }
                level++;
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