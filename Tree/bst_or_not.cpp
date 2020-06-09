#include<iostream>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

bool IsSubtreeLesser(TreeNode* root,int value)
{
    if(root==NULL)
        return true;
    if(root->val>value
    && IsSubtreeLesser(root->left,value)
    && IsSubtreeLesser(root->right,value))
        return true;
    else
        return false;
}
bool IsSubtreeGreater(TreeNode* root,int value)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->val<=value
    && IsSubtreeGreater(root->left,value)
    && IsSubtreeGreater(root->right,value))
    {
            return true;
    }
    else
    {
        return false;
    }
}
bool IsBinarySearchTree(TreeNode * root)
{
    if(IsSubtreeLesser(root->left,root->val)
    &&IsSubtreeGreater(root->right,root->val)
    &&IsBinarySearchTree(root->left)
    &&IsBinarySearchTree(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}