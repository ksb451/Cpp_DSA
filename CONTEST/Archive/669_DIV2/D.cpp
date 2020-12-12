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
	ll n;
    cin>>n;
    vector<ll>height(n);
    ll dp[n];
    for(int i=0;i<n;i++)
    {
   		cin>>height[i];
   		dp[i]=INT_MAX;
	}
    vector<int>lgr(n),rgr(n),lle(n),rle(n);
	vector<pii>st;
	st.clear();
	for(int i=0;i<n;i++)
	{
		while(st.empty()==false && st.back().first<height[i])
		{
			st.pop_back();
		}
		if(st.empty())
		{
			lgr[i]=-1;
		}
		else{
			lgr[i]=st.back().second;
		}
		st.push_back({height[i],i});
	}
	st.clear();
	for(int i=0;i<n;i++)
	{
		while(st.empty()==false && st.back().first>height[i])
		{
			st.pop_back();
		}
		if(st.empty())
		{
			lle[i]=-1;
		}
		else{
			lle[i]=st.back().second;
		}
		st.push_back({height[i],i});
	}st.clear();
	for(int i=n-1;i>=0;i--)
	{
		while(st.empty()==false && st.back().first<height[i])
		{
			st.pop_back();
		}
		if(st.empty())
		{
			rgr[i]=-1;
		}
		else{
			rgr[i]=st.back().second;
		}
		st.push_back({height[i],i});
	}st.clear();
	for(int i=n-1;i>=0;i--)
	{
		while(st.empty()==false && st.back().first>height[i])
		{
			st.pop_back();
		}
		if(st.empty())
		{
			rle[i]=-1;
		}
		else{
			rle[i]=st.back().second;
		}
		st.push_back({height[i],i});
	}
	st.clear();
	vector<int>jump[n];
	for(int i=0;i<n;i++)
	{
		if(rle[i]!=-1)jump[i].push_back(rle[i]);
		if(rgr[i]!=-1)jump[i].push_back(rgr[i]);
		if(lle[i]!=-1)jump[lle[i]].push_back(i);
		if(lgr[i]!=-1)jump[lgr[i]].push_back(i);
	}
	
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int to :jump[i])
		{
			dp[to]=min(dp[to],dp[i]+1);
		}
	}
	cout<<dp[n-1]<<endl;
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