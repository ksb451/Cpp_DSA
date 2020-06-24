// { Driver Code Starts
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
int mindist(vector<int>&dist,vector<bool>&sptset)
{
    int min=INT_MAX;
    int min_ind=-1;
    for(int i=0;i<dist.size();i++)
    {
        if(dist[i]<=min&&sptset[i]==false)
        {
            min=dist[i];
            min_ind=i;
        }
    }
    return min_ind;
}
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int>dist(V,INT_MAX);
    vector<bool>sptset(V,false);
    dist[src]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=mindist(dist,sptset);
        sptset[u]=true;
        for(int j=0;j<V;j++)
        {
            if(sptset[j]==false&&g[u][j]&&dist[u]!=INT_MAX&&dist[u]+g[u][j]<=dist[j])
            {
                dist[j]=dist[u]+g[u][j];
            }
        }
    }
    return dist;
    
    // Your code here
}