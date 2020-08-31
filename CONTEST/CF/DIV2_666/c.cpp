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
    vector<ll>arr(n);
    read(arr);
    if(n==1)
    {
    	cout<<"1 1"<<endl;
    	cout<<-1*(arr[0])<<endl;
    	cout<<"1 1"<<endl;
    	cout<<0<<endl;
    	cout<<"1 1"<<endl;
    	cout<<0<<endl;
    	return;
    }
    if(n==2)
    {
    	cout<<"1 1"<<endl;
    	cout<<-1*(arr[0])<<endl;
    	cout<<"2 2"<<endl;
    	cout<<-1*(arr[1])<<endl;
    	cout<<"1 2"<<endl;
    	cout<<"0 0"<<endl;
    	return;
    }
    cout<<1<<" "<<n-1<<endl;
    for(int i=0;i<n-1;i++)
    {
    	cout<<(n-1)*(arr[i]%n)<<" ";
    	arr[i]+=(n-1)*(arr[i]%n);
    }
    cout<<endl;
    cout<<2<<" "<<n<<endl;
    for(int i=1;i<n;i++)
    {
    	if(i==n-1)
    	{
    		cout<<(n-1)*(arr[i]%n)<<" ";
    		arr[i]+=(n-1)*(arr[i]%n);
    	}
    	else{
    		cout<<0<<" ";
    	}
    }
    cout<<endl;
    cout<<1<<" "<<n<<endl;
    for(int i=0;i<n;i++)
    {
    	cout<<(-1)*(arr[i])<<" ";
    }
    cout<<endl;
    }

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}