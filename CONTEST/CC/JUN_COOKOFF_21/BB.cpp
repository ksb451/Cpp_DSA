/* Nitin Madhukar */
#include<bits/stdc++.h>
#include <algorithm>

#define ll              long long
#define mp              make_pair
#define lb              lower_bound
#define ub              upper_bound
#define all(x)          x.begin(), x.end()
#define big(x)          greater<x>()

#define sp              fixed<<setprecision
#define vi              vector<int>
#define vll             vector<ll>
#define vvi             vector<vi>
#define vvll            vector<vll>
#define pi              pair<int,int>
#define pll             pair<ll,ll>

#define PI              3.14159265
#define MOD             (int)1000000007
#define LINF            LONG_MAX
#define NL              LONG_MIN
#define INF             INT_MAX
#define NI              INT_MIN

#define IOS()           ios_base::sync_with_stdio(0);cin.tie(0);
#define deb(x)          cerr<<#x<<" : "<<x<<"\n";
#define deball(x)       for(auto iit:x) cerr<<" "<<iit;cerr<<"\n";
#define rep(i,b,c)      for(i=b; i<c; ++i)
#define rrep(i,b,c)     for(i=b; i>=c; --i)

#define IN              cin >>
#define OUT             cout <<
#define endl            "\n"
#define allr(a)         (a).rbegin(), (a).rend()
#define pb              push_back
#define fi              first
#define se              second
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

using namespace std;

void printt(vector<vll> &ans){
    for(auto i:ans)
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<'\n';
    
}
void solve1(vll &arr)
{
    ll n = arr.size();
    ll k,x=-1;
    k=1;
    for(int i=3;i<n;i+=2)
    {
        if(arr[i]==arr[k])
        {
            continue;
        }
        else{
            x=i;
            break;
        }
    }
    vector<vll>ans;
    if(x==-1)
    {
        cout<<"0\n";
        return;
    }
    for(int i=0;i<n;i+=2){
        ans.push_back({k+1,x+1,i+1});
        arr[i] = (arr[k]^arr[x]);
    }
    for(int i=1;i<n;i+=2){
        ans.push_back({1,3,i+1});
        arr[i] = (arr[0]^arr[2]);
    }
    cout<<ans.size()<<endl;
    printt(ans);
    return;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    read(arr);

    if(n==1){
        cout<<"0\n";
        return;
    }
    if(n==2){
        if(arr[0]!=arr[1]){
        cout<<"0\n";
        }
        else{
            cout<<"-1\n";
        }
        return;
    }
    if(n==3){
        if((arr[0]==arr[2]) and (arr[0]!=arr[1])){
        cout<<"0\n";
            return;
        }
        if((arr[0]==arr[2]) && (arr[0]==arr[1]))
        {
            if(arr[0]==0)
            {
        cout<<"-1\n";
                return;
            }
        cout<<"1\n";
            cout<<"1 3 2\n";
            return;
        }
        if(arr[1]==0)
        {
            if(arr[0]!=0){
        cout<<"1\n";
                cout<<"1 2 3"<<endl;
                return;
            }
            if(arr[2]!=0){
        cout<<"1\n";
                cout<<"3 2 1"<<endl;
                return;
            }
        }
        cout<<"-1\n";
        return;
    }
    if(count(all(arr),0)==n)
    {
        cout<<"-1\n";
        return;
    }
    ll k,x=-1;
    k=0;
    for(ll i=2;i<n;i+=2){
        if(arr[i]!=arr[k]){
            x=i;
            break;
        }
        else continue;
    }
    vector<vll>ans;
    if(x==-1){
        if(arr[0]==0){
            solve1(arr);
            return;
        }
        for(int i=1;i<n;i+=2){
            ans.pb({1,3,i+1});
            arr[i] = (arr[0]^arr[2]);
        }
        cout<<ans.size()<<endl;
        printt(ans);
        return; 
    }
    for(int i=1;i<n;i+=2)
    {
        ans.pb({k+1,x+1,i+1});
        arr[i] = (arr[k]^arr[x]);
    }
    for(int i=0;i<n;i+=2)
    {
        ans.pb({2,4,i+1});
        arr[i] = (arr[1]^arr[3]);
    }
    cout<<ans.size()<<endl;
    printt(ans);
    return;
}

int main(){
    IOS();
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; ++i)
        solve();

return 0;
}