#include<stack>
#include<iostream>
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class BSTIterator
{
private:
    TreeNode* curr;
    stack<TreeNode*> S;
public:
    BSTIterator(TreeNode *);
    ~BSTIterator();
    int next();
    bool hasNext();
};

BSTIterator::~BSTIterator()
{
}


BSTIterator::BSTIterator(TreeNode *root) {
    curr=root;
}

/** return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(curr==NULL&&S.empty())
    {
        return false;
    }
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int value;
    while(1)
    {
        if(curr!=NULL)
        {
            S.push(curr);
            curr=curr->left;
            continue;
        }
        if(S.empty())
        {
            break;
        }
        value=S.top()->val;
        curr=S.top()->right;
        S.pop();
        break;
    }
    return value;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
