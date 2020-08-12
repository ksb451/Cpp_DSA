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

const int N = 50000;

void player_1() {
    cout << "Ashishgup" << endl;
}

void player_2() {
    cout << "FastestFinger" << endl;
}

bool check_prime(int n) {
    for (int i = 2; i < min(N, n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        bool lose = (n == 1);
        if (n > 2 && n % 2 == 0) {
            if ((n & (n - 1)) == 0)
                lose = 1;
            else if (n % 4 != 0 && check_prime(n / 2))
                lose = 1;
        }
        if (lose)
            player_2();
        else player_1();
    }
}