//https://www.interviewbit.com/problems/interleaving-strings/
// Given A, B, C, find whether C is formed by the interleaving of A and B.
// Input 1:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbcbcac"

// Output 1:
//     1
#include<string>
#include<vector>
using namespace std;
bool check(string &A,string &B,string &C,int a,int b,int c,vector<vector<int>>&dp)
{
    if(c==0)
    {
        return 1;
    }
    if(dp[a][b]!=-1)
    {
        return dp[a][b];
    }
    else
    {
        if(a>0&&b>0&&(C[c]!=A[a]&&C[c]!=B[b]))
            return dp[a][b]=false;
        else if(a>0&&b>0&&C[c]==A[a]&&C[c]==B[b])
            return dp[a][b]=(check(A,B,C,a,b-1,c-1,dp)||check(A,B,C,a-1,b,c-1,dp));
        else if(a>0&&C[c]==A[a])
            return dp[a][b]=check(A,B,C,a-1,b,c-1,dp);
        else if(b>0&&C[c]==B[b])
            return dp[a][b]=check(A,B,C,a,b-1,c-1,dp);
    }
}

int isInterleave(string A, string B, string C) {
    int a=A.length();
    int b=B.length();
    int c=C.length();
    if(c!=a+b)
        return false;
    vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
    return check(A,B,C,a-1,b-1,c-1,dp);
}
