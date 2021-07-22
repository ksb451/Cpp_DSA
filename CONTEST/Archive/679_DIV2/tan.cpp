//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using ll = long long int;


const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void solve()
{
	ll k;
    cin>>k;
    pair<ll,ll>S,F;
    cin>>S.first>>S.second;
    cin>>F.first>>F.second;
    ll n;
    cin>>n;
    map<pair<ll,ll>,pair<ll,ll>>adj;
    for(int i=0;i<n;i++)
    {
    	ll a,b,c,d;
    	cin>>a>>b>>c>>d;
    	adj[{a,b}]={c,d};
    	adj[{c,d}]={a,b};
    }
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
}

int main()
{
    
    solve();
    return 0;
}