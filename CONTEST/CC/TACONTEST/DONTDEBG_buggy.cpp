#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define MAX_N 100002
 
vector < int > graph[MAX_N], rev_graph[MAX_N];
 
bool visited[MAX_N] = {0};
bool visited2[MAX_N] = {0};
 
int indegree[MAX_N] = {0};
int represent_node[MAX_N] = {0};
 
void dfs(int node, stack < int > &s) {
    visited[node] = true;
    
    for (int x: graph[node])
        if (!visited[x])
            dfs(x, s);
 
    s.push(node);
}
 
void dfs2(int node, int representative) {
    visited2[node] = true;
    represent_node[node] = representative;
 
    for (int x: rev_graph[node])
        if (!visited2[x])
            dfs2(x, representative);
}
 
int main() {
    FIO;
    int t, n, m, k, i, j, ans;
    cin >> t;
    while (t--> 0) {
        cin >> n >> m;
        for(int i=0;i<MAX_N;i++)
        {
            graph[i].clear();
            rev_graph[i].clear();
            visited2[i]=0;
            visited[i]=0;
            represent_node[i]=i;
            indegree[i]=0;
        }
        while (m--> 0) {
            cin >> j >> k;
            graph[--j].push_back(--k);
            rev_graph[k].push_back(j);
        }
 
        stack < int > s;
 
        for (i = 0; i < n; i++)
            if (!visited[i])
                dfs(i, s);
 
        while (s.size() > 0) {
            j = s.top();
            s.pop();
            if (!visited2[j])
                dfs2(j, j);
        }
 
        for (i = 0; i < n; i++)
            for (int x: graph[i])
                if (represent_node[i] != represent_node[x])
                    indegree[represent_node[x]]++;
        ans=0;
        for (i = 0; i < n; i++)
            if (represent_node[i] == i)
                if(indegree[i] == 0)
                    ans++;
        cout << ans << "\n";
    }
    return 0;
} 