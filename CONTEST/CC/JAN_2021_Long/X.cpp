/* Nitin Madhukar */
#include<bits/stdc++.h>

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

ll mindp(vector<ll>&a,ll n,ll x,ll sum){
    ll dp[n+1][sum+1];
    for(ll i=0;i<=n;i++)dp[i][0]=1;
    for(ll i=1;i<=sum;i++)dp[0][i]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(a[i-1]>j)continue;
            else dp[i][j]|=dp[i-1][j-a[i-1]];
        }
    }
    for(ll i=x;i<=sum;i++)
    {
        if(dp[n][i]==1)
        {
            return 0;
        }
    }
    return 1;
}
bool checksu(ll a,ll &x,ll &y){
    return((a>=x)&&(a<=y));
}
void solve() {
    ll n,x,y;cin>>n>>x>>y;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];    
        if(checksu(sum, x,y))
        {
            cout<<0<<"\n";
            return;
        }
    }
    if(mindp(a,n,x,y)){
        cout<<-1<<'\n';
        return;
    }
    sum=0;
    for(ll i=0;i<n;i++){
        sum+=a[i];
        for(ll j=0;j<=i;j++){
            for(ll k=i+1;k<n;k++){
                if(checksu(sum-a[j]+a[k],x,y)){
                    cout<<1<<'\n';
                    return;
                }
            }
        }
    }
    cout<<2<<'\n';
}
int main(){
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; ++i)
        solve();

return 0;
}