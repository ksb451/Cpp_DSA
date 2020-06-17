#include <iostream>
#include<vector>
#include<string>
using namespace std;

int editdistance(string &A,string &B,int n,int m)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(A[i-1]==B[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}

int main() {
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cin.get();
        string A,B;
        cin>>A;
        cin>>B;
        a=A.length();
        b=B.length();
        //cout<<A<<a<<B<<b<<endl;
        cout<<editdistance(A,B,a,b)<<endl;
    }
	//code
	return 0;
}