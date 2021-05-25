#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int &e : a) {
        cin >> e;
    }
    for (int &e : b) {
        cin >> e;
    }
    b.push_back(0);
    ll ans = 1e18;
    ll cur = 0;
    ll bal = 0;
    for (int i = 0; i < n; i++) {
        ans = min(ans, cur + max(0ll, c - bal + a[i] - 1) / a[i]);
        ll newDays = max(0ll, b[i] - bal + a[i] - 1) / a[i];
        cur += newDays + 1;
        bal += a[i] * newDays - b[i];
    }
    cout << ans << "\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}