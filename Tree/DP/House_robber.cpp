// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

// https: //leetcode.com/problems/house-robber-iii/

//Definition for a binary tree node.

#include <bits/stdc++.h>
using namespace std;

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
    int tryRob(TreeNode *root, int &l, int &r)
    {
        if (!root)
            return 0;

        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);

        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode *root)
    {
        int l, r;
        return tryRob(root, l, r);
    }
};