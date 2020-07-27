// 106. Construct Binary Tree from Inorder and Postorder Traversal

// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};
class Solution
{
    TreeNode *construct(vector<int> &postorder, unordered_map<int, int> &mp, int pstart, int pend, int istart, int iend)
    {
        if (pstart > pend)
        {
            return NULL;
        }
        else
        {
            int mid = mp[postorder[pend]];
            TreeNode *root = new TreeNode(postorder[pend]);
            int l = mid - istart;
            int r = iend - mid;
            root->left = construct(postorder, mp, pstart, pstart + l - 1, istart, mid - 1);
            root->right = construct(postorder, mp, pstart + l, pstart + l + r - 1, mid + 1, iend);
            return root;
        }
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return construct(postorder, mp, 0, n - 1, 0, n - 1);
    }
};