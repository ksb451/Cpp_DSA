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

void first_sq(vector<vector<ll>>&org,vector<vector<ll>>&curr, vector<vector<ll>>&change,ll k, ll corner)
{
	ll j= corner;
	ll i= corner;
	ll curr_k;
	cout<<1<<" "<<i<<" "<<j<<endl;
	cout<<flush;
	change[i][j]++;
	cin>>curr_k;
	if(curr_k < k)
	{
		curr[i][j]=1;
		curr[i+1][j]=1;
		curr[i+1][j+1]=1;
		curr[i][j+1]=0;
	}
	else{
		for(int i=0;i<n;i++)
		{
			for(int )
		}
	}

}

void solve()
{
	ll n,q,k;
    cin>>n>>q>>k;
   	vector<vector<ll>>org(n,vector<ll>(n,0));
   	vector<vector<ll>>curr(n,vector<ll>(n,0));
   	vector<vector<ll>>change(n,vector<ll>(n,0));

   	ll curr_k;


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