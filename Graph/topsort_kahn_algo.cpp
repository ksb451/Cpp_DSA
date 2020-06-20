#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector<int> topsort(vector<int>adj[],int V)
{
    vector<int>in_degree(V,0);
    int visited=0;
    for(int i=0;i<V;i++)
    {
        for(auto j :adj[i])
        {
            in_degree[j]++;//count incoming edgess to all the vertex;
        }
    }
    queue<int>Q;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
        {
            Q.push(i);//add vertex with no in-coming edgess;
        }
    }
    vector<int>toporder;
    while(!Q.empty())
    {
        int curr=Q.front();
        Q.pop();
        toporder.push_back(curr);
        visited++;
        for(auto j:adj[curr])
        {
            in_degree[j]--;//cut all the edges from curr to any vetex with this loop
            if(in_degree[j]==0)//as soon as by cutting edge any vertex become with in _degree 0 add it to queue
            {
                Q.push(j);
            }
        }
    }
    if(visited!=V)//if there is  loop those will not get procesed completly so visited will be less than v
    {
        cout<<"not possible"<<endl;
        return vector<int>();
    }
    return toporder;
    
}