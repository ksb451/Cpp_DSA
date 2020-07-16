#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long mod = 1e9 + 7;

int n, q;
string s;
int queries[MAXN];
void solve()
{
    n = s.length();
    stack<int> st;
    vector<int> nxt(n, -2);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (st.size() > 0)
            nxt[st.top()] = i, st.pop();
    }
    for (i = n - 2; i >= 0; i--)
    {
        if (s[i] == ')')
            nxt[i] = nxt[i + 1];
    }
    for (i = 0; i < q; i++)
        cout << nxt[queries[i] - 1] + 1 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s >> q;
        int i = 0;
        for (i = 0; i < q; i++)
            cin >> queries[i];
        solve();
    }
    return 0;
}