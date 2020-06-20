#include<vector>
#include<stack>
#include<iostream>
using namespace std;
void dfsutil(int curr,vector<int>adj[],vector<bool>&visited,vector<int>&curr_scc)
{
    visited[curr]=true;
    curr_scc.push_back(curr);
    for(auto j:adj[curr])
    {
        if(visited[j]==false)
            dfsutil(j,adj,visited,curr_scc);
    }
}

void dfsutil_scc(int curr,vector<int>adj[],vector<bool>&visited,stack<int>&S)
{
    visited[curr]=true;
    for(auto j:adj[curr])
    {
        if(visited[j]==false)
            dfsutil_scc(j,adj,visited,S);
    }
    S.push(curr);
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    stack<int>S;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            dfsutil_scc(i,adj,visited,S);
        }
    }
    vector<int>Tr_adj[V];
    for(int i=0;i<V;i++)
    {
        for(auto j:adj[i])
        {
            Tr_adj[j].push_back(i);
        }
    }
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    int count=0;
    vector<int>curr_scc;
    vector<vector<int>>all_scc;
    while(!S.empty())
    {
        int curr=S.top();
        S.pop();
        if(visited[curr]==false)
        {
            curr_scc.clear();
            count++;
            dfsutil(curr,Tr_adj,visited,curr_scc);
            all_scc.push_back(curr_scc);
        }
    }
    //all_scc contain all the strongly connected components
    return count;//conut is no of strongly connnected components
}
