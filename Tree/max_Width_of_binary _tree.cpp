
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

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
    int widthOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }
        unordered_map<int, int> left_most;
        queue<pair<TreeNode *, unsigned long long int>> Q;
        Q.push({root, 1});
        int lvl = 1;
        int prev_amt = 1;
        unsigned long long max_width = 1;
        while (Q.empty() == false)
        {
            int curr_amt = 0;
            while (prev_amt--)
            {
                pair<TreeNode *, unsigned long long> temp = Q.front();
                Q.pop();
                if (left_most.find(lvl) == left_most.end())
                {
                    left_most[lvl] = temp.second;
                }
                else
                {
                    max_width = max(max_width, temp.second - left_most[lvl] + 1);
                }
                if (temp.first->left != NULL)
                {
                    Q.push({temp.first->left, temp.second * 2});
                    curr_amt++;
                }
                if (temp.first->right != NULL)
                {
                    Q.push({temp.first->right, temp.second * 2 + 1});
                    curr_amt++;
                }
            }
            prev_amt = curr_amt;
            lvl++;
        }
        return max_width;
    }
};