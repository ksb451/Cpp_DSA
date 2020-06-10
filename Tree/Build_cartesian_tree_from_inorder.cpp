// Definition for binary tree
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* buildTree(vector<int> &A) {
    if(A.empty())
    {
        return NULL;
    }
    TreeNode* head=new TreeNode(A[0]);//make the root node equel to first value
    for(int i=1;i<A.size();i++)
    {
        if(A[i]<=head->val)//if value is less than go to right becasue "inorder" 
        {
            TreeNode* temp=head;
            while(temp->right!=NULL)//goto right utill right is null
            {
                if(temp->right->val<=A[i])//if right is less than stop as we have to take care of condition that parent is greater than childeren
                    break;
                temp=temp->right;
            }
            if(temp->right==NULL)//if we reached rightmost than justt attach it
            {
                temp->right=new TreeNode(A[i]);
            }
            else//if not tan make the new node attach to the right of parent and the right subtree the left subtree of newnode
            {
                TreeNode* temp2=new TreeNode(A[i]);
                temp2->left=temp->right;
                temp->right=temp2;
            }
        }
        else if(A[i]>head->val)//if value is greater make newnode with the value and attach the give tree as its left subtree
        {
            TreeNode * temp=new TreeNode(A[i]);
            temp->left=head;
            head=temp;
        }
    }
    return head;
}
