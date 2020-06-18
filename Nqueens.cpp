#include<vector>
#include<string>
#include<iostream>
using namespace std;
bool issafe(vector<string>&currform,int row,int i,int A)
{
    for(int j=row;j>=0;j--)
    {
        if(currform[j][i]=='Q')
        {
            return false;
        }
    }
    for(int j=row, k=i;j>=0&&k<A;j--,k++)
    {
        if(currform[j][k]=='Q')
        {
            return false;
        }
    }
    for(int j=row, k=i;j>=0&&k>=0;j--,k--)
    {
        if(currform[j][k]=='Q')
        {
            return false;
        }
    }
    return true;
}

void backtrack(vector<vector<string>>&ans,vector<string>currform,int row,int A)
{
    if(row==A)
    {
        ans.push_back(currform);
        return;
    }
    for(int i=0;i<A;i++)
    {
        if(issafe(currform,row,i,A))
        {
            currform[row][i]='Q';
            backtrack(ans,currform,row+1,A);
            currform[row][i]='.';
        }
    }
}


vector<vector<string> > solveNQueens(int A) {
    vector<vector<string>>ans;
    if(A==1)
    {
        vector<string>q;
        q.push_back("Q");
        ans.push_back(q);
        return ans;
    }
    if(A<4)
    {
        return ans;
    }
    string row=string(A,'.');
    vector<string>currform;
    for(int i=0;i<A;i++)
    {
        currform.push_back(row);
    }
    backtrack(ans,currform,0,A);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
