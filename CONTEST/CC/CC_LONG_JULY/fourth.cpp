#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		ll a,b;
		cin>>n;
		n=((n*4)-1);
		unordered_set<ll>x_cor,y_cor;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			if(x_cor.count(a))
			{
				x_cor.erase(a);
			}
			else{
				x_cor.insert(a);
			}
			if(y_cor.count(b))
			{
				y_cor.erase(b);
			}
			else{
				y_cor.insert(b);
			}
		}
		cout<<*x_cor.begin()<<" "<<*y_cor.begin()<<endl;
	}
}