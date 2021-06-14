#include <iostream>
#include <string>
#include <deque>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) 
    {
        std::string s;
        if (root == nullptr)
        {
            return "[null]";
        }

        s = "[";
        q.push_back(root);
        while (!q.empty())
        {
            TreeNode* now{ q.front() };
            if (now != nullptr)
            {
                s += (std::to_string(now->val) + ",");
                q.push_back(now->left);
                q.push_back(now->right);
            }
            else
            {
                s += "null,";
            }
            q.pop_front();
        }

        s.erase(s.end() - 1);
        return s + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) 
    {
        q.clear();
        size_t index{ 0 };
        std::vector<std::string> v;
        data.erase(data.begin());
        data.erase(data.end() - 1);
        splitString(data, v, ',');

        if (data == "null")
        {
            return nullptr;
        }

        TreeNode* root{ new TreeNode(std::stoi(v[index])) };
        q.push_back(root);
        index++;

        while (!q.empty())
        {
            TreeNode* now{ q.front() };
            TreeNode* left{ nullptr }, * right{ nullptr };

            if (v[index] != "null")
            {
                left = new TreeNode(std::stoi(v[index]));
                q.push_back(left);
            }

            now->left = left;
            index++;

            if (v[index] != "null")
            {
                right = new TreeNode(std::stoi(v[index]));
                q.push_back(right);
            }

            now->right = right;

            index++;
            q.pop_front();
        }

        return root;
    }

private:
    std::deque<TreeNode*> q;


    void splitString(const std::string& s, std::vector<std::string>& tokens, const char& delim = ' ') {
        tokens.clear();
        size_t lastPos = s.find_first_not_of(delim, 0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != std::string::npos) {
            tokens.emplace_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delim, pos);
            pos = s.find(delim, lastPos);
        }
    }
};

int main()
{
    Codec solution = Codec();

    std::cout << solution.serialize(new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4), new TreeNode(5)))) << std::endl;
    TreeNode* root{ solution.deserialize("[1,2,3,null,null,4,5,null,null,null,null]") };
    std::cout << solution.serialize(root) << std::endl;

    return 0;
}