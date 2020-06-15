
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

int Solution::numDistinct(string A, string B) {
    int l=A.length();
    int m=B.length();
    vector<vector<int>>dp(l+1,vector<int>(m+1,-1));
    return recur(A,B,l,m,dp);
}
