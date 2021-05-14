/* Nitin Madhukar */
#include<bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define ll              long long
#define mp              make_pair
#define pb              push_back
#define lb              lower_bound
#define ub              upper_bound
#define all(x)          x.begin(), x.end()
#define big(x)          greater<x>()

#define sp              fixed<<setprecision
#define vi              vector<int>
#define vvi             vector<vi>
#define pi              pair<int,int>

#define PI              3.14159265
#define M               (int)1000000007
#define LINF            LONG_MAX
#define NL              LONG_MIN
#define INF             INT_MAX
#define NI              INT_MIN

#define IOS()           ios_base::sync_with_stdio(0);cin.tie(0);
#define deb(x)          cerr<<#x<<" : "<<x<<"\n";
#define deball(x)       for(auto iit:x) cerr<<" "<<iit;cerr<<"\n";
#define rep(i,b,c)      for(i=b; i<c; ++i)
#define rrep(i,b,c)     for(i=b; i>=c; --i)

using namespace std;

string s;
int dp[5005][5005];
bool ispal[5005][5005];
int n;
int q;
void memoise(int i,int j){
    if(i>=j){
        dp[i][j]=0;
        ispal[i][j]=1;
        return;
    }
    else if(dp[i][j]!=-1)
        return ;
    else
    {
        ispal[i][j]=0;
        int ans=0;
        memoise(i+1,j);
        memoise(i+1,j-1);
        memoise(i,j-1);

        if((s[i]==s[j]) && (ispal[i+1][j-1])){
            ispal[i][j]=1;
            ans++;
        }
        ans+=dp[i+1][j];
        ans-=dp[i+1][j-1];
        ans+=dp[i][j-1];

        dp[i][j]=ans;
        return;
    }  
}

void solve() 
{
    cin>>s;
    n=s.length();
    memset(dp,-1,sizeof(dp));
    memset(ispal,0,sizeof(ispal));
    
    memoise(0,(n-1));
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<dp[l][r]+(r-l+1)<<"\n";
    }
   return;
}
int main(){
    fast;
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; ++i)
        solve();

return 0;
}