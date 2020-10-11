//**sn0wrus**//
#include <bits/stdc++.h>

using namespace std;


int	solve2(int **mine, int m, int n)
{
	int ans = INT_MIN;
		for(int i = n-2;i>=0;i--)
		{
			for(int j =0 ;j<m;j++)
			{
				if(j==0)
				{
					mine[j][i]= mine[j][i]+(max(mine[j][i+1], mine[j+1][i+1]));
				}
				else if(j==m-1)
				{
					mine[j][i]= mine[j][i]+(max(mine[j-1][i+1], mine[j][i+1]));
				}
				else{
					mine[j][i]= mine[j][i]+(max(mine[j][i+1], max(mine[j+1][i+1], mine[j-1][i+1])));
				}
			}
		}	
		for(int i=0;i<m;i++)
		{
			ans = max(ans, mine[i][0]);
		}
		return ans;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	int **arr;
	arr = new int *[n];
	for(int i = 0;i <n;i++)
	{
		arr[i]  = new int[m];
		for(int j = 0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<solve2(arr,n ,m)<<endl;
}

int main()
{
    
    int tc = 1;
    cin>> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}