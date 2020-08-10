#include <bits/stdc++.h>
using namespace std;
const int MAX=1e3+9;
map<string, int> mp;
string s[MAX], v[MAX], u[MAX];
int n, m, ans;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>s[i];
    sort(s, s+n);
    for (int i=0;i<n;i++) mp[s[i]]=i;
    for (int i=0;i<m;i++) cin>>v[i]>>u[i];
    for (int i=0;i<(1<<n);i++)
    {
        bool f=1;
        for (int j=0;j<m;j++)
            if ((i&(1<<mp[v[j]])) && (i& (1<< mp[u[j]])))
                f=0;
        if (f && __builtin_popcount(ans)<__builtin_popcount(i))
            ans=i;
    }
    cout<<__builtin_popcount(ans)<<'\n';
    for (int i=0;i<n;i++)
        if (ans&(1<<i))
            cout<<s[i]<<'\n';
}