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
	ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>arr;
    for(int i=0;i<k;i++){
    	ll a,b,c,d;
    	cin>>a>>b>>c>>d;
    	arr.push_back({a,b,c,d});
    }
    ll cost=0;
    vector<ll>save(m,0);
    vector<ll>mark(m+1,0);
    vector<vector<ll>>mark_l(m);
    vector<vector<ll>>mark_r(m);
    for(int i=0;i<k;i++)
    {
    	ll x1 = arr[i][0];
    	ll y1 = min(arr[i][1],arr[i][3]);
    	ll x2 = arr[i][2];
    	ll y2 = max(arr[i][1],arr[i][3]);
    	x1--;
    	x2--;
    	y1--;
    	y2--;
    	ll hor = abs(x1-x2);
    	ll ver = abs(y1-y2);
    	cost += ((hor+ver)*2);
    	ll dis = hor/4;
    	ll beg = max(y1-dis,0LL);
    	ll end = min(y2+dis,m-1);
    	mark[beg]+=hor;
    	mark[end+1]-=hor;
    	mark_l[y2].push_back(dis);
    	mark_r[y1].push_back(dis);
    }
    ll x=0;
    for(int i=0;i<m;i++)
    {
    	x+=mark[i];
    	save[i]+=x;
    }
    unordered_map<ll,ll>um;
    ll cnt=0;
    for(ll i=0;i<m;i++)
    {
    	save[i]-=(cnt*4);
    	for(auto j:mark_l[i])
    	{
    		um[i+j]++;
    		cnt++;
    	}
    	cnt-=um[i];
    }
    cnt=0;
    um.clear();
    for(ll i=m-1;i>=0;i--)
    {
    	save[i]-=(cnt*4);
    	for(auto j:mark_r[i])
    	{
    		um[i-j]++;
    		cnt++;
    	}
    	cnt-=um[i];
    }
    ll mx=0;
    for(int i=0;i<m;i++)
    {
    	mx = max(mx,save[i]);
    }
    cout<<cost-mx<<endl;
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