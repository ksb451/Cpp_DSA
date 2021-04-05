//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
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
#define IN cin >>
#define OUT cout <<
//#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

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

void solve()
{
	ll d,n;
    cin>>n>>d;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    vector<ll>A;
    for(int i=0;i<n;i++)
    {
        if((arr[i]%10)==5)
        {
            if(d==5 || d==0)
            {
                A.push_back(arr[i]);
            }
        }
        else if((arr[i]%10)==0)
        {
            if(d==0)
            {
                A.push_back(arr[i]);
            }
        }
        else if(arr[i]&1)
        {
            A.push_back(arr[i]);
        }
        else{
            if((d&1)==0)
                A.push_back(arr[i]);
        }
    }
    ll ans=accumulate(all(A),1,std::multiplies<ll>());

    //cout<<ans<<endl;
    
    if((ans%10)==d)
    {
        if(A.size()==0)
        {
            cout<<-1<<endl;
            return;
        }
        cout<<A.size()<<endl;
        write(A);
        return;
    }

    if(d==0)
    {
        if((ans%10)!=0){
            cout<<-1<<endl;
            return;
        }
    }
    else if(d==5)
    {
        if((ans%10)!=5)
        {
            cout<<-1<<endl;
            return;
        }
    }
    multiset<ll>S(all(A));
    n =A.size();
    vector<vector<pair<ll,multiset<ll>>>>dp(n,vector<pair<ll,multiset<ll>>>(10,{INT_MAX,{}}));
    for(int i=0;i<n;i++)
    {
        //cout<<i<<endl;
        if(i==0)
        {
            dp[i][(A[i]%10)].first = A[i];
            dp[i][(A[i]%10)].second.insert(A[i]);
        }
        else{
            //cout<<A[i]<<endl;
            if(dp[i][(A[i]%10)].first > A[i])
            {
                dp[i][(A[i]%10)].first = A[i];
                dp[i][(A[i]%10)].second.clear();
                dp[i][(A[i]%10)].second.insert(A[i]);
            }
            for(int j=0;j<10;j++)
            {
                if(dp[i-1][j].first!=INT_MAX)
                {
                    ll curr = dp[i-1][j].first * A[i];
                    ll x = curr%10;
                    auto s = dp[i-1][j].second;
                    s.insert(A[i]);
                    if(dp[i][x].first > curr)
                    {
                        dp[i][x].first = curr;
                        dp[i][x].second = s;
                    }
                    if(dp[i][j].first > dp[i-1][j].first)
                    {
                        dp[i][j].first = dp[i-1][j].first;
                        dp[i][j].second = dp[i-1][j].second;
                    }
                }
            }
        }
    }
    ll mx=-1;
    multiset<ll>s;
    for(int i=0;i<10;i++)
    {
        ll curr = dp[n-1][i].first;
        ll dd = ans/curr;
        if(((dd)%10)==d)
        {
            if(dd > mx)
            {
                mx=dd;
                s=dp[n-1][i].second;
            }
        }
    }
    if(mx == -1)
    {
        cout<<-1<<endl;
        return;
    }
    for(auto i:s)
    {
        auto x = S.find(i);
        S.erase(x);
    }
    if(S.size()==0)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<S.size()<<endl;
    for(auto i:S)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}