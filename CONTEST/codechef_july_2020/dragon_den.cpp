#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,Q;
	cin>>n>>Q;
	vector<ll>den_height;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		den_height.push_back(x);
	}
	vector<ll>taste;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		taste.push_back(x);
	}
	while(Q--)
	{
		ll query_t, a,b;
		cin>>query_t>>a>>b;
		if(query_t==1)
		{
			taste[a-1]=b;
		}
		else{
			ll src=b-1;
			ll dest=a-1;
			if(src==dest)
			{
				cout<<taste[src]<<endl;
				continue;
			}
			if(den_height[dest]<=den_height[src])
			{
				cout<<-1<<endl;
				continue;
			}
			ll dir=(dest-src)/abs(dest-src);
			ll next=src+dir;
			ll curr=src;
			ll total_taste=taste[src];
			ll flag=true;
			while(next!=dest)
			{
				if(den_height[next]>=den_height[dest])
				{
					flag=false;
					break;
				}
				if(den_height[next]>den_height[curr])
				{
					curr=next;
					total_taste+=taste[curr];
				}
				next+=dir;
			}
			if(flag==false)
			{
				cout<<-1<<endl;
			}
			else{
				cout<<total_taste+taste[dest]<<endl;
			}
		}
	}
	return 0;
}