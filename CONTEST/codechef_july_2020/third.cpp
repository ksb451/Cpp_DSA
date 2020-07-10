#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

#define ll long long 
#define llf long long double
void print_ans(const vector<string>&v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	cout<<endl;
}

bool isvalid(int x,int y)
{
	if(x>=8||x<0)
	{
		return false;
	}
	if(y>=8||y<0)
	{
		return false;
	}
	return true;
}

void bfs(vector<string>&ans, ll k)
{
	ll count=1;
	queue<pair<int,int>>Q;
	Q.push({4,4});
	int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
	while(Q.empty()==false)
	{
		pair<int,int>temp=Q.front();
		Q.pop();
		for(int i=0;i<8;i++)
		{
			int x=temp.first+dir[i][0];
			int y=temp.second+dir[i][1];
			if(isvalid(x,y)&&ans[x][y]=='X'&&count<k)
			{
				Q.push({x,y});
				ans[x][y]='.';
				count++;
			}
		}
	}
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll k;
		cin>>k;
		vector<string>ans(8,"XXXXXXXX");
		ans[4][4]='O';
		if(k==1)
		{
			print_ans(ans);
		}
		else{
			bfs(ans,k);
			print_ans(ans);
		}
	}
	return 0;
}