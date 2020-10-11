//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
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
	ll n,m;
    cin>>n>>m;
    vector<pll>r(n);
    vector<pll>l(m);
    for(int i=0;i<n;i++)cin>>r[i].first>>r[i].second;
    for(int i=0;i<m;i++)cin>>l[i].first>>l[i].second;

    vector<pll>xx;
    int ansx = 0, ansy = 0;
	for(int i=0; i<n; i++){
		int rx = r[i].first, ry = r[i].second;
		for(int j=0; j<m; j++){
			int lx = l[j].first, ly = l[j].second;
			int x = 0, y = 0;
			if(rx > lx || ry > ly)
				continue;
			else if(rx < lx && ry > ly){
				x = lx-rx+1;
			}
			else if(rx > lx && ry < ly){
				y = ly-ry+1;
			}
			else{
				x = lx-rx+1;
				y = ly-ry+1;
			}
			//cout<<x<<" "<<y<<endl;
			xx.push_back({x,y});
		}
	}
	sort(all(xx));
	multiset<int, greater<int>>jset;
	for(auto i: xx)
	{
		jset.insert(i.second);
	}
	int ans = *(jset.begin());
	for(auto i:xx)
	{
		int temp=0;
		temp += i.first;
		auto itr = jset.find(i.second);
		if(itr!=jset.end()){
   			jset.erase(itr);
   		}
   		temp+=*(jset.begin());
   		ans = min(ans,temp);
	}
	cout<<ans<<endl;

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