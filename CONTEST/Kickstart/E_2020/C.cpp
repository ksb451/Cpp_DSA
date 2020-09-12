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

void solve()
{
    ll n;
    cin>>n;
    ll sum=0;
    vector<ll>E(n),R(n);
    set<pll>st;
    for(int i=0;i<n;i++)
    {
    	cin>>E[i];
    	sum+=E[i];
    }
    for(int i=0;i<n;i++)
    {
    	cin>>R[i];
    }
    bool flag =true;
    for(int i=0;i<n;i++)
    {
    	if(sum-E[i]<R[i])
    	{
    		flag=false;
    		break;
    	}
    	st.insert({E[i]+R[i],i});
    }
    if(flag)
    {
    	if(n==1)
    	{
    		cout<<0<<" "<<sum<<endl;
    	}
    	else{
    		cout<<0<<" "<<"INDEFINITELY"<<endl;
    	}
    	return;
    }
    while(true)
    {
    	if(st.begin())
    }

    
    
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