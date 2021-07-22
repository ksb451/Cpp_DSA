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
ll n,m,k;
unordered_map<string,ll>pat;
void fill(set<ll>&S, string str, ll i)
{
	if(i==k)
	{
		S.insert(pat[str]);
	}
	else{
		string temp = str;
		fill(S,temp,i+1);
		temp[i]='_';
		fill(S,temp,i+1);
	}
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		pat[s]=i+1;
	}
	vector<ll>arr(m,0);
	vector<string>str;
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s;
		str.push_back(s);
		cin>>arr[i];
	}
	vector<set<ll>>match(n);
	for(int i=0;i<n;i++)
	{
		fill(match[i], str[i], 0);
		for(auto j:match[i])
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
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