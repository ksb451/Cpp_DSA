#include<queue>
struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void levelorder(TreeNode* root){
    if(root==NULL)return;
    queue<TreeNode*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* curent=Q.front();
        cout<<current->val<<" ";
        if(currnet->left!=NULL)
            Q.push(current->left);
        if(current->right!=NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}