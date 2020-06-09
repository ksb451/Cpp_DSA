#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void print(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    print(root->left);
    //cout<<root->val<<" ";//inorder
    print(root->right);
    //cout<<root->val<<" ";//postorder
}
void flatten(TreeNode * head)
{
    if(head==NULL)
    {
        return;
    }
    if(head->left!=NULL)
    {
        flatten(head->left);
        TreeNode* temp=head->left;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=head->right;
        head->right=head->left;
        head->left=NULL;
    }
    if(head->right!=NULL)
    {
        flatten(head->right);
    }
    
}
int main()
{
    TreeNode *A=new TreeNode(1);
    A->left=new TreeNode(2);
    A->right=new TreeNode(4);
    A->right->right=new TreeNode(6);
    A->right->left=new TreeNode(5);
    A->left->right=new TreeNode(3);
    print(A);
    cout<<endl;
    flatten(A);
    print(A);
    cout<<endl;
    return 0;
}