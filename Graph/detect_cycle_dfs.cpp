// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool dfscycleundir(vector<int>g[],int i, vector<bool>&visited,int parent)
{
    visited[i]=true;
    for(auto j:g[i])
    {
        if(visited[j]==false)
        {
            if(dfscycleundir(g,j,visited,i))
                return true;
        }
        else
        {
            if(j!=parent)
                return true;
        }
    }
    return false;
}
bool isCyclicundirected(vector<int> g[], int V)
{
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(dfscycleundir(g,i,visited,-1))
                return true;
        }
    }
    return false;
   // Your code here
   
}


//for directed graph
bool isCyclicUtil(vector<int>adj[], int curr, vector<bool>&visited, vector<bool>&recstack)
{
    visited[curr]=true;
    recstack[curr]=true;//add in curr recursion stack
    for(auto j:adj[curr])
    {
        if(!visited[j])
        {
            if(isCyclicUtil(adj,j,visited,recstack))
                return true;
        }
        else if(recstack[j]==true)
                return true;
    }
    recstack[curr]=false;//remove from current recursion stack as we get out of a function
    return false;
}
bool isCyclicdir(int V, vector<int> adj[])
{
    vector<bool>visited(V,false);
    vector<bool>recstack(V,false);//to mark node in current recursion stack
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(isCyclicUtil(adj,i,visited,recstack))
                return true;
        }
    }
    return false;
    // Your code here
}
