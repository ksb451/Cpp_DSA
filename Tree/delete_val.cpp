#include<iostream>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode* delete_val(TreeNode* root,int data)
{
    if(root==NULL) return root;
    else if(data<root->val)
    { 
        root->left=delete_val(root->left,data);
    }
    else if (data>root->val)
    {
        root->right=delete_val(root->right,data);
    }
    else
    {
        
    }
    
    
}