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
#define FOR(i,n)        \
    for(int i=0;i<n;i++)
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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    
    if(((a-c)+(b-c)+c > n)||(n>1&& (a==c&&b==c&&c==1)))
    {
    	cout<<"IMPOSSIBLE"<<endl;
    	return;
    }
    for(int i=0;i<a-c;i++)
    {
    	cout<<n-1<<" ";
    }
    if(c==1&&a>c)
    {
    	for(int i=0;i<(n-((a-c)+(b-c)+c));i++)
    	{
    		cout<<n-2<<" ";
    	}
    }
    cout<<n<<" ";
    if(c>1)
    {
    	for(int i=0;i<(n-((a-c)+(b-c)+c));i++)
    	{
    		cout<<n-2<<" ";
    	}	
    }
    for(int i=0;i<c-1;i++)
    {
    	cout<<n<<" ";
    }

    if(c==1&&a==c){
    	for(int i=0;i<(n-((a-c)+(b-c)+c));i++)
    	{
    		cout<<n-2<<" ";
    	}
    }
   	for(int i=0;i<b-c;i++)
   	{
   		cout<<n-1<<" ";
   	}
   	cout<<endl;
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