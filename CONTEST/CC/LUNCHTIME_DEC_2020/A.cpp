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
		string s;
		cin>>s;
		vector<ll>arr(26,0);
		for(auto i:s)
		{
			arr[i-'a']++;
		}
		ll ans=0;
		multiset<ll>M;
		for(auto i:arr){
			if(i>0)
			{
				M.insert(i);
			}
		}
		while(M.empty()==false)
		{
			if(M.size()==1)
			{
				break;
			}
			ll mn = *M.begin();
			ll mx = *(prev(M.end()));
			M.erase(M.begin());
			M.erase(prev(M.end()));
			if(mn<2 && mx<2)
			{
				break;
			}
			ll x = min(mn,(mx/2));
			ans+=x;
			mn-=x;
			mx-=(x*2);
			if(mn>0)
				M.insert(mn);
			if(mx>0)
				M.insert(mx);

		}
		for(auto i:M){
			ans+= (i/3);
		}
		cout<<ans<<endl;
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