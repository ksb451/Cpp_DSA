// Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is 
// identical to the sequence B.

// Subsequence : A subsequence of a string is a new string which is formed from the original string by 
// deleting some (can be none) of the characters without disturbing the relative positions of the 
// remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).
// Input 2:
//     A = "rabbbit" 
//     B = "rabbit"

// Output 2:
//     3
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int recur(string &A, string& B, int l,int m, vector<vector<int>>&dp)
{
    if(m==0)
    {
        return dp[l][m]=1;
    }
    if(l==0)
    {
        return dp[l][m]=0;
    }
    if(l<m)
    {
        return dp[l][m]=0;
    }
    else
    {
        if(dp[l][m]!=-1)
            return dp[l][m];
        else
        {
            if(A[l-1]==B[m-1])
            {
                return dp[l][m]=recur(A,B,l-1,m,dp)+recur(A,B,l-1,m-1,dp);
            }
            else
            {
                return dp[l][m]=recur(A,B,l-1,m,dp);
            }
        }
    }
}

int numDistinct(string A, string B) {
    int l=A.length();
    int m=B.length();
    vector<vector<int>>dp(l+1,vector<int>(m+1,-1));
    return recur(A,B,l,m,dp);
}
