/******************************************
* AUTHOR : Keshab Agrawal *
* NICK : sn0wrus *
******************************************/
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
{`
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
    cin>>m>>n;
    vector<pll>A(n);
    vector<ll>B(n);
    for(int i=0;i<n;i++)
    {
		cin>>A[i].first>>A[i].second;
    	B[i]=A[i].first;
    }
    sort(all(B));
    // for(int i=0;i<n;i++)
    // {
    // 	cout<<B[i]<<" ";
    // }
    // cout<<endl;
    vector<ll>pre=B;
    for(int i=n-2;i>=0;i--)
    {
    	pre[i]+=pre[i+1];
    }
    // for(int i=0;i<n;i++)
    // {
    // 	cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll sum=0;
		ll pos = B.end()-upper_bound(all(B),A[i].second);
		//cout<<pos<<" "<<A[i].second<<endl;
		if(pos>=m && pos)
			sum=*(pre.end()-m);
		else{
			if(pos)
				sum=*(pre.end()-pos);
			if(A[i].first>A[i].second)
			{
				sum+=(m-pos)*A[i].second;
			}
			else{
				sum+=A[i].first;
				sum+=(m-pos-1)*A[i].second;
			}
		}
		ans=max(sum,ans);
	}
	cout<<ans<<endl;
}

int main()
{
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}