// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++)
        {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++)
            {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}

static int dir[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

bool isvalid(int x, int y, int N, int M)
{
    if (x < 0 || x >= N)
        return false;
    if (y < 0 || y >= M)
        return false;
    return true;
}

void dfsutil(vector<int> A[], vector<vector<int>> &visited, int x, int y, int N, int M)
{
    visited[x][y] = 1;
    for (int d = 0; d < 8; d++)
    {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if (isvalid(nx, ny, N, M))
        {
            if (visited[nx][ny] == false && A[nx][ny] == 1)
            {
                dfsutil(A, visited, nx, ny, N, M);
            }
        }
    }
}

int findIslands(vector<int> A[], int N, int M)
{
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == 1)
            {
                if (visited[i][j] == 0)
                {
                    ans++;
                    dfsutil(A, visited, i, j, N, M);
                }
            }
        }
    }
    return ans;

    // Your code here
}
