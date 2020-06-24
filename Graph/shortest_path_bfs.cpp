#include <iostream>
#include<vector>
#include<queue>
using namespace std;

bool isvalid(int x,int y,int m,int n)
{
    if(x<0||x>=m)
        return false;
    if(y<0||y>=n)
        return false;
    return true;
}

int minstep(vector<vector<int>>&G,int dx,int dy)
{
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int m=G.size();
    int n=G[0].size();
    queue<int>xq;
    queue<int>yq;
    xq.push(0);
    yq.push(0);
    int step=1;
    int prev=1;
    int curr=0;
    bool flag=false;
    while(xq.empty()==false&&yq.empty()==false&&flag==false)
    {
        while(prev--)
        {
            int x=xq.front();
            int y=yq.front();
            xq.pop();
            yq.pop();
            for(int d=0;d<4;d++)
            {
                if(x+dir[d][0]==dx&&y+dir[d][1]==dy)
                {
                    return step;
                }
                if(isvalid(x+dir[d][0],y+dir[d][1],m,n))
                {
                    if(G[x+dir[d][0]][y+dir[d][1]]==1)
                    {
                        xq.push(x+dir[d][0]);
                        yq.push(y+dir[d][1]);
                        curr++;
                    }
                }
            }
        }
        prev=curr;
        curr=0;
        step++;
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        vector<vector<int>>G(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x;
                cin>>x;
                G[i][j]=x;
            }
        }
        int dx,dy;
        cin>>dx>>dy;
        cout<<minstep(G,dx,dy)<<endl;
    }
    
	//code
	return 0;
}