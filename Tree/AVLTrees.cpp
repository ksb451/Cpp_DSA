#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNodeAVL
{
    int val;
    int height;
    TreeNodeAVL * left;
    TreeNodeAVL* right;
    TreeNodeAVL(int x):val(x),height(0),left(NULL),right(NULL){}
};

int height(TreeNodeAVL * root)
{
    if(root==NULL)
    {
        return -1;
    }
    return root->height;
}

TreeNodeAVL* leftrotate(TreeNodeAVL * node)
{
    TreeNodeAVL* temp=node->right;
    node->right=temp->left;
    temp->left=node;
    node->height=max(height(node->left),height(node->right))+1;
    temp->height=max(height(temp->left),height(temp->right))+1;
    return temp;
}

TreeNodeAVL* rightrotate(TreeNodeAVL * node)
{
    TreeNodeAVL* temp=node->left;
    node->left=temp->right;
    temp->right=node;
    node->height=max(height(node->left),height(node->right))+1;
    temp->height=max(height(temp->left),height(temp->right))+1;
    return temp;
}

int balanceof(TreeNodeAVL* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return height(root->left)-height(root->right);
    }
    
}

TreeNodeAVL* insert(TreeNodeAVL * root ,int key)
{
    if(root==NULL)
    {
        return new TreeNodeAVL(key);
    }
    if (key<root->val)
    {
        root->left=insert(root->left,key);
    }
    else if (key>root->val)
    {
        root->right=insert(root->right,key);
    }
    else
    {
        return root;
    }
    root->height=1+max(height(root->left),height(root->right));

    int balance=balanceof(root);
    if(balance>1 && key<root->left->val)
        return rightrotate(root);
    
    if(balance<-1 && key> root->right->val)
    {
        return leftrotate(root);
    }
    if(balance > 1 && key > root->left->val)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1 && key < root->right->val)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    } 
    return root;
}

void levelorder(TreeNodeAVL* root){
    if(root==NULL)return;
    queue<TreeNodeAVL*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        TreeNodeAVL* current=Q.front();
        cout<<current->val<<" ";
        if(current->left!=NULL)
            Q.push(current->left);
        if(current->right!=NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}

void preorder(TreeNodeAVL* node)
{
    if(node!=NULL)
    {
        cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(TreeNodeAVL* node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }
}

void postorder(TreeNodeAVL* node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout<<node->val<<" ";
    }
}
int main()
{
    TreeNodeAVL* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    root=insert(root,35);

    cout<<"preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"lvlorder"<<endl;
    levelorder(root);
    cout<<endl;
    return 0;
}

