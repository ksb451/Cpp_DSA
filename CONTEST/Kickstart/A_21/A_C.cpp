#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define nl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};



void solve()
{
    ll r,c;
    cin>>r>>c;
    vector<vector<ll>>grid(r,vll(c));
    auto cmp = [](const auto &a, const auto &b){
    	if(get<0>(a) > get<0>(b))
    	{
    		return true;
    	}
    	else if(get<0>(a) == get<0>(b))
    	{
    		if(get<1>(a) > get<1>(b))
	    	{
	    		return true;
	    	}
	    	else if(get<1>(a) == get<1>(b))
    		{
    			if(get<2>(a) > get<2>(b))
		    	{
		    		return true;
		    	}
    		}
    	}
    	return false;
    };
    multiset<tuple<ll,ll,ll>,decltype(cmp)>S(cmp);
    for(int i=0;i<r;i++)
    {
    	for(int j=0;j<c;j++)
    	{
    		cin>>grid[i][j];
    		S.insert({grid[i][j], i,j});		
       	}
    }
    ll ans=0;
    while(!S.empty())
    {
    	auto curr = *S.begin();
    	S.erase(S.begin());
    	ll x = get<1>(curr);
		ll y = get<2>(curr);
		ll val = get<0>(curr);
    	for(int i=0;i<4;i++)
    	{
    		ll xx = x + dir4[i][0];
    		ll yy = y + dir4[i][1];
    		if((xx >=0) && (xx< r) &&(yy>=0)&&(yy<c))
    		{
    			if(grid[xx][yy] < (val -1))
    			{
    				ll q =  (val - grid[xx][yy] -1);
    				ans += q;

    				auto tmp = S.find({grid[xx][yy], xx,yy});
    				S.erase(tmp);
    				grid[xx][yy]+=q;
    				S.insert({grid[xx][yy], xx,yy});
    			}
    		}	
    	}
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}