#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long int ll;

pair<ll, ll> max_p(pair<int, int> a, pair<int, int> b)
{

    if (a.first == -1)
    {
        return b;
    }
    else if (b.first == -1)
    {
        return a;
    }
    if (a.second > b.second)
    {
        return a;
    }
    return b;
}

void build_tree(vector<ll> &arr, vector<pair<ll, ll>> &seg_tree, ll l, ll r, ll pos)
{
    if (l == r)
    {
        seg_tree[pos] = {l, arr[l]};
        return;
    }
    ll mid = l + (r - l) / 2;
    build_tree(arr, seg_tree, l, mid, 2 * pos + 1);
    build_tree(arr, seg_tree, mid + 1, r, 2 * pos + 2);
    seg_tree[pos] = max_p(seg_tree[2 * pos + 1], seg_tree[2 * pos + 2]);
}

pair<ll, ll> range_max(ll left, ll right, vector<pair<ll, ll>> &seg_tree, vector<ll> &arr, ll low, ll high, ll pos)
{
    if (left <= low && right >= high)
    {
        return seg_tree[pos];
    }
    if (left > high || right < low)
    {
        return {-1, INT_MIN};
    }
    int mid = low + (high - low) / 2;

    return max_p(range_max(left, right, seg_tree, arr, low, mid, pos * 2 + 1), range_max(left, right, seg_tree, arr, mid + 1, high, pos * 2 + 2));
}

void print(vector<pair<ll, ll>> &seg_tree)
{
    for (auto j : seg_tree)
    {
        cout << j.first << " " << j.second << " ";
    }
    cout << endl;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    vector<pair<ll, ll>> seg_tree;
    for (int i = 0; i < 2 * n; i++)
    {
        seg_tree.push_back({-1, INT_MIN});
    }
    build_tree(arr, seg_tree, 0, n - 1, 0);
    print(seg_tree);
    cout << range_max(3, 4, seg_tree, arr, 0, n - 1, 0).second << " " << range_max(1, 3, seg_tree, arr, 0, n - 1, 0).second;
}