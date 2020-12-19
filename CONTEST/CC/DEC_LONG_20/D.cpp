//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

/*
for(int i=0;i<n-1;i++)
{
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
*/

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll i,sum=0;
    ll a[n+1];
    for(i=1;i<=n;i++)
    {
        if(k==0||k==n)
            break;
        if(sum<=1&&k>0){
            a[i]=i;
            sum+=i;
            k--;
            continue;
        }
        if(sum>i){
            a[i]=-i;
            sum-=i;
            if(sum>0)
                k--;
            continue;
        }
        if(sum>1&&k==1){
            a[i]=-i;
            if (sum-i>0)
                break;
            else
            {
                sum-=i;
                continue;
            }
        }
        if (sum>1&&k>1)
        {
            a[i]=i;
            if(sum>0)
                k--;
            sum+=i;
        }
    }
    if (k==n){
        for(i=1;i<=n;i++)
            a[i]=i;
    }
    else if(i<=n){
        for (;i<=n;i++)
            a[i]=-i;
    }
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}