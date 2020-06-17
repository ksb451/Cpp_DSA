#include<string>
#include<vector>
#include<iostream>
using namespace std;
//basic recursive function with huge overhead 
int recursive(string x,string y,int n,int m)
{
    if(n==0||m==0){
        return 0;
    }
    if(x[n-1]==y[m-1])
    {
        return 1+recursive(x,y,n-1,m-1);
    }
    else
    {
        return max(recursive(x,y,n,m-1),recursive(x,y,n-1,m));
    }
}
//top down approch with memoziation
int topdown(string &x,string &y,int n,int m,vector<vector<int>>&dp)
{
    if(n==0||m==0)
    {
        return dp[n][m]=0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(x[n-1]==y[m-1])
    {
        return dp[n][m]=1+topdown(x,y,n-1,m-1,dp);
    }
    else
    {
        return dp[n][m]=max(topdown(x,y,n,m-1,dp),topdown(x,y,n-1,m,dp));
    }
}
//bottom up approch no recursive call overhead.
int bottomup(string &x,string &y,int n,int m,vector<vector<int>>&dp)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
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
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        cout<<recursive(A,B,a,b)<<endl;
        cout<<topdown(A,B,a,b,dp)<<endl;
        cout<<bottomup(A,B,a,b,dp)<<endl;
    }
	//code
	return 0;
}