//To print the smallest super sequence

#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

string bottomup(string &x,string &y,int n,int m,vector<vector<int>>&dp)
{
    //first make the table as required
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
            else
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    string ans;
    int i=n,j=m;
    while(i>0||j>0)//cuild the ans from the tabee try by hand to understand the algorithm
    {
        if(i==0)
        {
            while(j>0)
            {
                ans.push_back(y[j-1]);
                j--;
            }
        }
        else if(j==0)
        {
            while(i>0)
            {
                ans.push_back(x[i-1]);
                i--;
            }
        }
        else
        {
            if(x[i-1]==y[j-1])
            {
                ans.push_back(x[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]<dp[i][j-1])
                {
                    ans.push_back(x[i-1]);
                    i--;
                }
                else
                {
                    ans.push_back(y[j-1]);
                    j--;
                }
            }
        }
    }
    //cout<<ans;
    reverse(ans.begin(),ans.end());//the answer we get is in reverse order so reverse it.
    return ans;
}

int main() {
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        int a,b;
        string A,B;
        cin>>A;
        cin>>B;
        cin.get();
        a=A.length();
        b=B.length();
        //cout<<A<<a<<B<<b<<endl;
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        //length of longest common subsequence
        string ans=bottomup(A,B,a,b,dp);
        cout<<ans<<endl;
    }
	//code
	return 0;
}