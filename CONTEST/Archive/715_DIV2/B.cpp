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
#define allr(a) (a).rbegin(), (a).rend()
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
	ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>T;
    vector<ll>M;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='T')
    	{
    		T.push_back(i);
    	}
    	else{
    		M.push_back(i);
    	}
    }
    if((M.size() *2) == T.size())
    {
    	vector<ll>pair;
    	ll j=0;
    	for(int i=0;i<M.size();i++)
    	{
    		if(M[i]> T[j])
    		{
    			pair.push_back(M[i]);
    			j++;
    		}
    		else{
    			cout<<"NO"<<endl;
    			return;
    		}
    	}
    	ll i=0;
    	for(;j<T.size();j++)
    	{
    		if(i < pair.size())
    		{
    			if(T[j] > pair[i])
    			{
    				i++;
    			}
    			else{
    				cout<<"NO"<<endl;
    				return;
    			}
    		}
    	}
    	cout<<"YES"<<endl;
    	return;
    }
    cout<<"NO"<<endl;
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