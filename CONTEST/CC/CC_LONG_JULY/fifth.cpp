#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<utility>
#include<unordered_set>
#include<set>
#include<iterator>
using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		unordered_map<ll,ll>A;
		unordered_map<ll,ll>B;
		set<ll>arr;
		multiset<ll>a;
		multiset<ll,greater<ll>>b;
		A.clear();
		B.clear();
		arr.clear();
		a.clear();
		b.clear();
		for(ll i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			if(!arr.count(x))
				arr.insert(x);
			if(A.find(x)==A.end())
			{
				A[x]=1;
			}
			else{
				A[x]+=1;
			}
		}
		for(ll i=0;i<n;i++)
		{

			ll x;
			cin>>x;
			arr.insert(x);
			if(B.find(x)==B.end())
			{
				B[x]=1;
			}
			else{
				B[x]+=1;
			}
		}
		bool flag=true;
		auto q=arr.begin();
		for(auto x:arr)
		{
			ll a_count;
			ll b_count;
			if(A.find(x)==A.end())
			{
				a_count=0;
			}
			else{
				a_count=A[x];
			}
			if(B.find(x)==B.end())
			{
				b_count=0;
			}
			else{
				b_count=B[x];
			}
			if((a_count+b_count)%2==1)
			{
				flag=false;
				break;
			}
			else{
				if(a_count>b_count)
				{
					ll temp=(a_count-b_count)/2;
					while(temp--)
					{
						a.insert(x);
					}
				}
				else if(b_count>a_count)
				{
					ll temp=(b_count-a_count)/2;
					while(temp--)
					{
						b.insert(x);
					}
				}
			}
		}
		//cout<<endl;
		if(flag==false)
		{
			cout<<"-1"<<endl;
		}
		else{
			if(a.size()!=b.size())
			{
				cout<<"-1"<<endl;
			}
			else{
				ll min_no=*arr.begin();
				ll ans=0;
				auto i=a.begin();
				auto j=b.begin();
				for(;i!=a.end()&&j!=b.end();i++,j++)
				{
					ans+=min(2*min_no, min(*i, *j));
				}
				cout<<ans<<endl;
			}
		}
	}	
	return 0;
}