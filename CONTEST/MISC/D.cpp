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
#define fi first
#define se second

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

ll sq(ll i)
{
    return i*i;
}

ll val(ll len,ll nums){
    ll unit=len/nums;
    ll extra=len-unit*nums;
    
    return (nums-extra)*sq(unit)+extra*sq(unit+1);
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    priority_queue<plll>pq;
    ll cost =0;
    for(int i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        cost+= sq(t);
        pq.push({val(t,1)-val(t,2),{t,2}});
    }
    for(int i=0;i<(k-n);i++)
    {
        cost-=pq.top().fi;
        ll a = pq.top().se.fi;
        ll b = pq.top().se.se;
        pq.pop();

        pq.push({val(a,b)-val(a,b+1),{a,b+1}});
    }
    cout<<cost<<endl;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}