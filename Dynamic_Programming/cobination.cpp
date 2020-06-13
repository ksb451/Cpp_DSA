//to find nCr using dp
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long int lld;

lld combination(lld n,lld r)
{
    vector<vector<lld>>dp(n+1,vector<lld>(n+1,0));//intitalize table with zeros;
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;//all nc0 are equle to one;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];//pascal triangle approch
        }
    }
    return dp[n][r];
}


//driver code

// int main()
// {
//     int t=1;
//     cin>>t;
//     while(t--)
//     {

//     }
//     return 0;
// }