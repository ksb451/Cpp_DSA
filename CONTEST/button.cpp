#include<bits/stdc++.h>
using namespace std;


string make_string(vector<deque<int>>&state)
{
	int n=state.size();
	string temp="S";
	temp+=to_string(n);
	temp+="__";
	for(int i=0;i<n;i++)
	{
		temp+=to_string(state[i].size());
		temp+="_";
		for(auto j:state[i])
		{
			temp+=to_string(j);
			temp+="_";
		}
		temp+="_";
	}
	return temp;
}

//S3__1_0__1_1__1_2__
//S3__3_1_2_0__0__0__


vector<deque<int>> make_state(string& temp)
{
	stringstream ss(temp);
	char a;
	ss>>a;
	int n;
	ss>>n;
	vector<deque<int>>state(n);
	ss>>a;
	ss>>a;
	for(int i=0;i<n;i++)
	{
		int sz;
		ss>>sz;
		while(sz-->0)
		{
			ss>>a;
			int b;
			ss>>b;
			state[i].push_back(b);
		}
		ss>>a;
		ss>>a;
	}
	return state;
}

void solve(){
	int n;
	cin>>n;
	vector<deque<int>>state(n);
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		while(a-->0)
		{
			int b;
			cin>>b;
			state[i].push_back(b);
		}
	}
	vector<deque<int>>final(n);
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		while(a-->0)
		{
			int b;
			cin>>b;
			final[i].push_back(b);
		}
	}
	string start=make_string(state);
	string result=make_string(final);
	
	unordered_map<string,int>visited;
	queue<string>Q;
	Q.push(start);
	visited[start]=0;
	while(!Q.empty())
	{
		string curr_string=Q.front();
		Q.pop();
		vector<deque<int>>curr_state=make_state(curr_string);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(curr_state[i].size()!=0)
				{
					int button=curr_state[i][0];
					curr_state[i].pop_front();
					curr_state[j].push_back(button);
					string next=make_string(curr_state);
					if(next==result)
					{	
						cout<<visited[curr_string]+2<<endl;
						return;
					}
					if(visited.find(next)==visited.end())
					{
						visited[next]=visited[curr_string]+2;
					}
					curr_state[j].pop_back();
					curr_state[i].push_front(button);
				}
			}
		}
	}
	cout<<-1<<endl;
	return;
}


int main(){
	int t;
	cin>>t;
	while(t-->0)
	{
		solve();
	}
}