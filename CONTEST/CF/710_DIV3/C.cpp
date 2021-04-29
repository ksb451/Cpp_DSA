#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mod2 998244353
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define speed ios_base::sync_with_stdio(false) \
    ;cin.tie(NULL) \
    ;cout.tie(NULL)
#define in(a) \
    for(auto &i:a) \
        cin>>i;
#define prnt(a) \
    for(auto i:a) \
        cout<<i<<" "; \
    cout<<endl;



ll power(ll x, ll y, ll m){
    if(y==0)
        return 1;
    ll p=power(x,y/2,m);
    p=(p*p)%m;
    return (y%2)?(p*x)%m:p;
}

ll modInverse(ll x, ll m){
    return power(x,m-2,m);
}

void solve(){
    string a,b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    int dp[n+1][m+1]={};
    int mx=INT_MIN;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 or j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                mx=max(mx,dp[i][j]);
            }
        }
    }
    cout<<(n-mx)+(m-mx)<<endl;
}

int main(){
    speed;
    ll t;
    cin>>t;
//    t=1;
    while(t--){
        solve();
    }
}
