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
    vector<ll>arr(n*2LL);
    unordered_map<ll,ll>um;
    for(ll i=0;i<(2LL*n);i++){
    	cin>>arr[i];
    	um[arr[i]]++;
    }
    vector<ll>arr2;
    for(auto i: um)
    {
    	if(i.second != 2LL)
    	{
    		cout<<"NO"<<endl;
    		return;
    	}
    	if(i.first==0)
    	{
    		cout<<"NO"<<endl;
    		return;
    	}
    	if((i.first % 2LL) == 1)
		{
			cout<<"NO"<<endl;
			return;
		}
		arr2.push_back(i.first);
    }
    sort(all(arr2));
    //write(arr2);
    ll nn  = arr2.size();
    vector<ll>rem;
    if(nn==1)
    {
    	cout<<"YES"<<endl;
    	return;
    }
    else{
    	for(ll i=1LL;i<nn;i++)
    	{
    		ll curr = arr2[i]-arr2[i-1];
    		if((curr % (i*2LL))!=0)
    		{
    			cout<<"NO"<<endl;
    			return;
    		}
    		ll qq = curr/(i*2LL);
    		rem.push_back(qq);
    		//cout<< curr/(i*2)<<" ";
    	}
    	ll xx = 0LL;
    	ll z = rem.size();
    	for(ll j  =0 ;j<z;j++)
    	{
    		xx += (rem[j]*(z-j));
    	}
    	ll first = arr2[0]/2LL;
    	if((((first - xx) % nn )== 0LL) && ((first-xx)!=0LL))
    	{
    		cout<<"YES"<<endl;
    		return;
    	}
    	else{
    		cout<<"NO"<<endl;
    		return;
    	}
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