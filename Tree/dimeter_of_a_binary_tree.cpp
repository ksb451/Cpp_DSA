#include <iostream>
#include <climits>
using namespace std;
//   Definition for a binary tree node.
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
    int diameter(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int l = diameter(root->left, ans);
            int r = diameter(root->right, ans);
            ans = max(ans, 1 + l + r);
            return max(l, r) + 1;
        }
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int ans = INT_MIN;
        diameter(root, ans);
        return ans - 1;
    }
};