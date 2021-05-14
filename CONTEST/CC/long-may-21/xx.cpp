#include<bits/stdc++.h>
    using namespace std; 
    int main(){
        int n; cin >> n;
        vector<vector<int>> graph(n+1);
        for(int i=1; i<=n; i++){
            int x; cin >> x;
            if(x == -1) continue;
            graph[x].push_back(i);
        }
        
        // for(int i=1; i<=n; i++){
        // 	for(auto x : graph[i]){
        // 		cout << x << " ";
        // 	}
        // 	cout << endl;
        // }
        
        int ans = 1;
        vector<int> vis(n+1,0);
        queue<pair<int,int>> q;     //index,grp
        for(int i=1; i<=n; i++){
            
            if(vis[i] != 0 ) 
            	continue;
            
            q.push({i,1});
            vis[i] = 1;   
            while(!q.empty()){
                int curr = q.front().first;
                int grp = q.front().second;
                q.pop();
                for(int nbr : graph[curr]){
                    vis[nbr] = grp+1;
                    ans = max(ans,grp+1);
                    q.push({nbr,grp+1});
                }
            }
        }
        cout<< ans;
        return; 
    }