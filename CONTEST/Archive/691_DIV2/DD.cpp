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
//#define endl "\n"
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
//const ll M = 998244353LL;

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
    vector<ll>save(m,0);
    vector<vector<ll>>mark_l(m);
    vector<vector<ll>>mark_r(m);
    vector<ll>mark(m+1,0);
    ll cost=0;
    for(int i=0;i<k;i++)
    {
    	ll x1=arr[i][0];
    	ll x2=arr[i][2];
    	ll y1=min(arr[i][1],arr[i][3]);
    	ll y2=max(arr[i][1],arr[i][3]);
    	x1--;
    	x2--;
    	y1--;
    	y2--;
    	cost+=abs(x1-x2);
    	cost+=abs(y2-y1);
    	ll hor = abs(x1-x2);
    	ll x=hor;
    	ll dis = hor/4;
    	ll beg  = max(0LL,y1-dis);
    	ll las = min(m-1,y2+dis);
    	//cout<<dis<<" "<<beg<<" "<<las<<endl;
    	mark[beg]+=hor;
    	mark[las+1]-=hor;
    	mark_l[y2].push_back(dis);
    	mark_r[y1].push_back(dis);
    	// for(ll j=y1;j>=0;j--)
    	// {
    	// 	if(x>0)
    	// 		save[j]+=x;
    	// 	x-=4;
    	// }
    	// x=hor;
    	// for(ll j=y2;j<m;j++)
    	// {
    	// 	if(x>0)
    	// 		save[j]+=x;
    	// 	x-=4;
    	// }
    	// for(ll j=y1+1;j<y2;j++)
    	// {
    	// 	save[j]+=hor;
    	// }
    	// if(y1==y2)
    	// {
    	// 	save[y1]-=hor;
    	// }
    }
    ll x=0;
    for(ll i=0;i<n;i++)
    {
    	x+=mark[i];
    	save[i]+=x;
    }
    // for(int i=0;i<m;i++)
    // {
    // 	cout<<save[i]<<" ";
    // }
    multiset<ll>M;
    for(ll i=0;i<m;i++)
    {
    	ll cnt=M.size();
    	//cout<<i<<" "<<cnt<<endl;
    	save[i]-=(4*cnt);
    	for(auto j:mark_l[i])
    	{
    		M.insert(i+j);
    	}
    	M.erase(i);
    }
    M.clear();
    for(ll i=m-1;i>=0;i--)
    {
    	
    	ll cnt=M.size();
    	//cout<<i<<" "<<cnt<<endl;
    	save[i]-=(4*cnt);
    	for(auto j:mark_r[i])
    	{
    		M.insert(i-j);
    	}
    	M.erase(i);
    }
    M.clear();
    ll max_save=0;
    for(int i=0;i<m;i++)
    {
    	//cout<<save[i]<<" ";
    	max_save = max(max_save,save[i]);
    }
    //cout<<endl;
    //cout<<max_save<<endl;
    cout<<(cost*2)-max_save<<endl;
    return;
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