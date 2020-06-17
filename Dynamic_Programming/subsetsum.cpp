#include<vector>
#include<numeric>
#include<iterator>
using namespace std;
//returns a n+1/sum+1 size table in which dp[i][j] denotes no of subset possible with sum j with first i elements of the array.
vector<vector<int>>subsetsum(vector<int>A, long long int sum)
{
    //long long int sum=accumulate(A.begin(),A.end(),0);//use this if we want to check forr all subset sum.
    int n=A.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i<=n;i++)
        {
            if(A[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-A[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp;
}