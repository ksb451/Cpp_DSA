//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#define for0(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=n-1;i>=0;i++)
#define IN cin >>
#define OUT cout <<
// #define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back

#define fi first
#define se second

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x ;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'<<endl;}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"<<endl;}
template<typename T, typename... Args>
void __print(T t, Args... args) // recursive variadic function
{
    cout << t <<" " ;
    __print(args...) ;
}
void nl()
{
    cout<<endl;
}

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;

const ll MOD = (ll)(1e9) + 7LL;
const ll MM = 998244353LL;
const ll INF  = INT_MAX;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

const ll MAXN = 200005;

/*
for(int i=0;i<n-1;i++)
{
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
*/


int solve() {
	int A;
	vector<vector<int>> B;
	int C, D;
	vector<vector<int>>E;
	cin>>A;
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		B.push_back({a,b,c});
	}
	cin>>C>>D;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		E.push_back({a,b,c});
	}
    vector<vector<pair<int,int>>>adj(A);
    vector<vector<pair<int,int>>>extra(A);
    for(auto i:B)
    {
        adj[i[0]-1].push_back({i[1]-1,i[2]});
    }
    for(auto i:E)
    {
        extra[i[0]-1].push_back({i[1]-1,i[2]});
    }
    multiset<array<int,3>>M;
    vector<vector<int>>dist(A,vector<int>(2,INT_MAX));
    dist[C-1][0]=0;
    dist[C-1][1]=0;
    M.insert({0,C-1,0});
    M.insert({0,C-1,1});
    //cout<<"start"<<endl;
    //cout<<M.size()<<endl;
    while(!M.empty())
    {
        auto curr = *M.begin();
        M.erase(M.begin());
        int u = curr[1];
        int d = curr[0];
        int use = curr[2];
        //cout<<u<<" "<<d<<" "<<use<<endl;
        for(auto edge:adj[u])
        {
            int v = edge.first;
            int dd = edge.second;
            cout<<v<<" "<<dd<<endl;
            if((d+dd) < dist[v][use])
            {
                cout<<"yes"<<endl;
                int temp = dist[v][use];
                cout<<temp<<endl;
                M.erase({temp,v,use});
                cout<<"erase"<<endl;
                dist[v][use] = d+dd;
                cout<<"d1"<<endl;
                temp = dist[v][use];
                M.insert({temp,v,use});
                cout<<"f1"<<endl;
                cout<<"yes2"<<endl;
            }
            cout<<"done"<<endl;
        }
        cout<<use<<endl;
        if(use==0){
            for(auto edge:extra[u])
            {

                int v = edge.first;
                int dd = edge.second;
                cout<<v<<" "<<dd<<endl;
                if((d+dd)<dist[v][1])
                {
                    M.erase({dist[v][1],v,1});
                    dist[v][1] = d+dd;
                    M.insert({dist[v][1],v,1});
                }
            }
        }
    }
    cout<<min(dist[D-1][0], dist[D-1][1])<<endl;
    return min(dist[D-1][0], dist[D-1][1]);
}

/*
1.check for ll for all variables. 
2.chec for return satement in correct places.
3.check brackets in all equation and order of conditions.
4.check custom compare funtions if any.
5.check logic carefully.
6.Dont get stuck on one approch.
*/

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        cout<<solve()<<endl;
        cout.flush();
    }
    return 0;
}