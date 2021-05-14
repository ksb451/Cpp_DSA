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
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double>ans;
    if(k==1)
    {
        vector<double>ans(nums.begin(), nums.end());
        return ans;
    }
    multiset<int>left,right;
    for(int i=0;i<k;i++)
    {
        left.insert(nums[i]);
    }
    for(int i=0;i<k/2;i++)
    {
        int x = *left.rbegin();
        right.insert(x);
        left.erase(left.find(x));
    }
    if(k&1)
    {
        ans.push_back(*left.rbegin());
    }
    else{
        double x = *left.rbegin();
        double y = *right.begin();
        ans.push_back( (x+y)/2.0 );
    }
    cout<<"check"<<endl;
    for(int i=k;i<nums.size();i++)
    {
        for(auto i:left)
        {
            cout<<i<<" ";
        }
        cout<<endl;

        for(auto i:right)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<i<<endl;
        if(left.find(nums[i-k])==left.end())
        {
            right.erase(right.find(nums[i-k]));
        }
        else{
            left.erase(left.find(nums[i-k]));
        }
        cout<<"dlt"<<endl;
        for(auto i:left)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:right)
        {
            cout<<i<<" ";
        }
        cout<<"done"<<endl;
        int curr = nums[i];
        if(left.empty())
        {
            int x = *right.begin();   
            if(curr<x)
            {
                left.insert(curr);
            }
            else{
                right.insert(curr);
            }
        }
        else
        {
            int x = *left.rbegin();   
            if(curr>x)
            {
                right.insert(curr);
            }
            else{
                left.insert(curr);
            }
        }
        for(auto i:left)
        {
            cout<<i<<" ";
        }
        cout<<endl;

        for(auto i:right)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        while(right.size()>left.size())
        {
            int x = *right.begin();
            left.insert(x);
            right.erase(right.find(x));
        }
        while(left.size()-right.size()>1)
        {
            int x = *left.rbegin();
            right.insert(x);
            left.erase(left.find(x));
        }
        if(k&1)
        {
            ans.push_back(*left.rbegin());
        }
        else{
            double x = *left.rbegin();
            double y = *right.begin();
            ans.push_back( (x+y)/2.0 );
        }   
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    __print(medianSlidingWindow(arr,3));
}

/*
1.check for ll for all variables. 
2.check brackets in all equation and order of conditions.
3.check custom compare funtions if any.
4.check logic carefully.
5.Dont get stuck on one approch.
*/

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
        cout.flush();
    }
    return 0;
}