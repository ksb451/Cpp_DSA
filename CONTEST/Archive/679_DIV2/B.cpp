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
ll q;
vector<unordered_map<int,int>>um;
bool compare(ll a,ll b)
{
	if(um[q][a]<um[q][b])
	{
		return true;
	}
	return false;
}

void solve()
{
	ll n, m;
		cin>>n>>m;
		map<int, vector<int> > mp;
		set<int> s;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			s.insert(x);
			mp[x].pb(x);
			for(int j=1; j<m; j++){
				int y;
				cin>>y;
				mp[x].pb(y);
			}
		}
		vector<vector<int> > ans;
		for(int i=0; i<m; i++){
			int flag = 0;
			for(int j=0; j<n; j++){
				int x;
				cin>>x;
				if(j == 0 && s.find(x) != s.end()){
					flag = 1;
				}
				if(flag == 1){
					ans.pb(mp[x]);
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
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