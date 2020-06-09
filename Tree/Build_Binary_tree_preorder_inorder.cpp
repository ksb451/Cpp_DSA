TreeNode* Build(vector<int> &A,vector<int> &B, int &Aind,unordered_map<int,int>&in_index,int Bstart,int Bend)
{
    if(Bstart>Bend)
    {
        return NULL;
    }
    int curr=A[Aind++];
    TreeNode *root=new TreeNode(curr);
    if(Bstart==Bend)
        return root;
    root->left=Build(A,B,Aind,in_index,Bstart,in_index[curr]-1);
    root->right=Build(A,B,Aind,in_index,in_index[curr]+1,Bend);
    return root;
}
TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    if(A.empty())
        return NULL;
    unordered_map<int,int>in_index;
    for(int i=0;i<B.size();i++)
    {
        in_index[B[i]]=i;
    }
    int Aind=0;
    TreeNode* root=Build(A,B,Aind,in_index,0,B.size()-1);
    return root;
}
