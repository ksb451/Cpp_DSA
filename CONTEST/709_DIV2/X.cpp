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
	int n;
    cin>>n;
    vector<int>ans;
    queue<int>Q;
    string x;
    int qq=1;
    cin>>x;
    Q.push(stoi(x));
    int curr=stoi(x);
    if(n==1)
    {
    	cout<<curr<<endl;
    	return;
    }
    int cnt=0;
    int nl=0;
    while(qq<n)
    {
    	if(nl+cnt==2)
    	{
    		if(nl==2)
    		{
    			ans.push_back(curr);
    		}
    		curr=Q.front();
    		Q.pop();
    		nl=0;
    		cnt=0;
    	}
    	cin>>x;
    	if(x=="-")
    	{
    		nl++;
    	}
    	else{
    		Q.push(stoi(x));
    		cnt++;
    	}
    }

    for(auto i:ans)
    {
    	cout<<i<<" ";
    }
    for(auto i:Q)
    {
    	cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}