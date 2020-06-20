#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void sccutil(int curr,vector<int>adj[],vector<int>&id,vector<int>&low_link,vector<bool>&in_stack,stack<int>&rec_stack,vector<vector<int>>&ans)
{
    static int time=0;
    id[curr]=low_link[curr]=time++;
    in_stack[curr]=true;
    rec_stack.push(curr);
    for(auto j:adj[curr])
    {
        if(id[j]==-1)
        {
            sccutil(j,adj,id,low_link,in_stack,rec_stack,ans);
            low_link[curr]=min(low_link[curr],low_link[j]);
        }
        else if(in_stack[j]==true)
        {
            low_link[curr]=min(low_link[curr],id[j]);
        }
    }
    vector<int>currscc;
    if(low_link[curr]==id[curr])
    {
        int x;
        while(rec_stack.top()!=curr)
        {
            x=rec_stack.top();
            currscc.push_back(x);
            in_stack[x]=false;
            rec_stack.pop();
        }
        x=rec_stack.top();
        currscc.push_back(x);
        in_stack[x]=false;
        rec_stack.pop();
        ans.push_back(currscc);
    }
}

int tarjan_scc(vector<int>adj[], int V)
{
    vector<int>id(V,-1);
    vector<int>low_link(V,-1);
    vector<bool>in_stack(V,false);
    stack<int>rec_stack;
    vector<vector<int>>ans;
    for(int i=0;i<V;i++)
    {
        if(id[i]==-1)
        {
            sccutil(i,adj,id,low_link,in_stack,rec_stack,ans);
        }
    }
    for(int i=0;i<ans.size();i++)//print all tha scc
    {
        for(auto j:ans[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return ans.size();
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>adj[n];
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        int ans=tarjan_scc(adj,n);
        cout<<ans<<endl;//output no of scc
    }
    
	//code
	return 0;
}