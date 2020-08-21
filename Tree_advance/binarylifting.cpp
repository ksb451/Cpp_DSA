#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define nl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

int N, D;
int depth[300010];
vector<int> adj[300010];
//vector<vector<int>> adj;
int par[20][300010];
//vector<vector<int>> par;

int leftMostSetBit(int x) //find the left most set bit
{
    int res;
    while (x)
    {
        res++;
        x = x >> 1;
    }
    return res;
}

int walk(int i, int k) //walk k steps up from node i
{
    for (int d = 0; d < D && i != -1; d++)
    {
        if ((1 << d) & k)
        {
            i = par[d][i];
        }
    }
    return i;
}
int lca(int i, int j) //lowest common encestor of node i and j
{
    if (depth[i] > depth[j])
    {
        i = walk(i, depth[i] - depth[j]);
    }
    if (depth[j] > depth[i])
    {
        j = walk(j, depth[j] - depth[i]);
    }
    if (i == j)
    {
        return i;
    }
    for (int d = D; d >= 0; d--)
    {
        if (par[d][i] != par[d][j]) //go upto the last node where parent of i and j are diff
        {
            i = par[d][i];
            j = par[d][j];
        }
    }
    return par[0][i]; //go up just one more node to get the LCA
}

int finalDest(int i, int j, int k)
{
    int lc = lca(i, j);
    int dist = depth[i] + depth[j] - 2 * depth[lc];
    //cout << dist << "dist ";
    if (k >= dist)
    {
        return j;
    }
    else
    {
        if (depth[i] - depth[lc] <= k)
        {
            return walk(i, k);
        }
        else
        {
            return walk(j, dist - k);
        }
    }
}

void buildParTable() //BUild the binary lifting table
{
    vector<bool> visited(N, false);
    queue<int> Q;
    Q.push(0);
    visited[0] = true;
    //BFS on the treee to store depth and store immidiate parent
    while (!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for (int j : adj[i])
            if (!visited[j])
            {
                visited[j] = true;
                depth[j] = depth[i] + 1; //depth of parent +1
                par[0][j] = i;           //2^0 steps up that is immidiate parent
                Q.push(j);
            }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     cout << par[0][i] << " ";
    // }
    // cout << endl;
    for (int d = 1; d <= D; d++)
    {
        for (int i = 0; i < N; i++)
        {
            int mid = par[d - 1][i];
            if (mid != -1)
            {
                par[d][i] = par[d - 1][mid]; //as par[1][a]=par[0][par[0][a]]; and so on
            }
        }
    }
}

void solve()
{
    cin >> N;
    D = leftMostSetBit(N); //max jump for any Node in case of a skwed tree
    //cout << D << endl;

    memset(depth, 0, sizeof(depth));
    for (int i = 0; i < 300010; i++)
    {
        adj[i].clear();
    }
    memset(par, -1, sizeof(par));

    // depth = vector<int>(N, 0);
    // adj = vector<vector<int>>(N);
    // par = vector<vector<int>>(D + 3, vector<int>(N + 2, -1)); //parent of stariting node i.e 0 is -1
    for (int i = 0; i < N; i++)
    {
        adj[i].clear();
    }
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    buildParTable();
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //cout << "Qno" << q << endl;
        cout << finalDest(a - 1, b - 1, c) + 1 << endl;
    }
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}