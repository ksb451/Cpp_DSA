//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

using ll = long long int;

void solve()
{
	ll n;
    cin>>n;
    cout.flush();
    ll l = 1;
    ll r = n;
    ll pr=-1;
    while(l<r)
    {
    	ll mid =l+(r-l)/2;
    	ll x;
    	if(pr==-1)
    	{
    		cout.flush();
	    	cout<<'?'<<" "<<l<<" "<<r<<endl;
	    	cout.flush();
	    	cin>>x;
    	}
    	else{
    		x=pr;
    	}
    	if(mid==l)
    	{
    		if(x==l)
    		{
    			l++;
    			break;
    		}
    		else{
    			break;
    		}
    	}
    	if(x<=mid)
    	{
    		cout<<'?'<<" "<<l<<" "<<mid<<endl;
	    	cout.flush();
	    	ll y;
	    	cin>>y;
	    	if(x==y)
	    	{
	    		r = mid;
	    		pr=y;
	    	}
	    	else{
	    		l = mid+1;
	    		pr=-1;
	    	}
    	}
    	else{
    		if((mid+1)==r)
    		{
    			r=mid;
    			pr=-1;
    			continue;
    		}
    		cout<<'?'<<" "<<mid+1<<" "<<r<<endl;	
	    	cout.flush();
	    	ll y;
	    	cin>>y;
	    	if(x==y)
	    	{
	    		l = mid+1;
	    		pr=y;
	    	}
	    	else{
	    		r = mid;
	    		pr=-1;
	    	}
    	}
    	
    }
    cout<<'!'<<" "<<l<<endl;
    return;
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