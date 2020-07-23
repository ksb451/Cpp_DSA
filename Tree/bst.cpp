#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> S;
        vector<int> ans;
        TreeNode *last = NULL;
        while (root || !S.empty())
        {
            if (root)
            {
                S.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *node = S.top();
                if (node->right && last != node->right)
                {
                    root = node->right;
                }
                else
                {
                    ans.push_back(node->val);
                    S.pop();
                    last = node;
                }
            }
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        if (!root)
            return v;
        TreeNode *temp = root;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            v.push_back(temp->val);
            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }
        return v;
    }
};
