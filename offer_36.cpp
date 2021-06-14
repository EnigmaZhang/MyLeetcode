#include <iostream>



class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int _val) 
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) 
    {
        Node* head{ root }, * tail{ root };

        if (root == nullptr)
        {
            return nullptr;
        }

        treeToDoublyListCore(root, head, tail);

        tail->right = head;
        head->left = tail;
        return head;
    }
public:
    void treeToDoublyListCore(Node* root, Node*& head, Node*& tail)
    {
        Node* leftHead{ nullptr }, * leftTail{ nullptr }, * rightHead{ nullptr }, * rightTail{ nullptr };
        
        if (root == nullptr)
        {
            head = nullptr;
            tail = nullptr;
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            head = root;
            tail = root;
            return;
        }

        if (root->left != nullptr)
        {
            treeToDoublyListCore(root->left, leftHead, leftTail);
        }

        if (root->right != nullptr)
        {
            treeToDoublyListCore(root->right, rightHead, rightTail);
        }

        if (leftHead && leftTail)
        {
            leftTail->right = root;
            root->left = leftTail;
            head = leftHead;
        }
        else
        {
            head = root;
            root->left = nullptr;
        }

        if (rightHead && rightTail)
        {
            rightHead->left = root;
            root->right = rightHead;
            tail = rightTail;
        }
        else
        {
            tail = root;
            root->right = nullptr;
        }
    }
};

int main()
{
    Solution solution = Solution();

    return 0;
}