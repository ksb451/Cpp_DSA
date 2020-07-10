#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long 
#define llf long long double

ll points(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans+=(x%10);
		x=(x/10);
	}
	return ans; 
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll score_a=0,score_b=0;
		ll a,b;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			a=points(a);
			b=points(b);
			if(a>b)
				score_a++;
			if(b>a)
				score_b++;
			if(a==b)
			{
				score_b++;
				score_a++;
			}
		}
		if(score_a>score_b)
		{
			cout<<0<<" "<<score_a<<endl;
		}
		else if(score_b>score_a)
		{
			cout<<1<<" "<<score_b<<endl;
		}
		else
		{
			cout<<2<<" "<<score_b<<endl;
		}
	}
	return 0;
}