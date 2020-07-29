// https : //www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/kth-element-2-7d970b44/description/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int ll;

class FenTree
{
    vector<int> ft;

public:
    FenTree(vector<int> &arr)
    {
        ft = arr;
        int n = ft.size();
        for (int i = 1; i < n; i++)
        {
            int parent = i + (i & (-i));
            if (parent < n)
            {
                ft[parent] += ft[i];
            }
        }
    }
    int getSum(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += ft[i];
            i -= (i & (-i));
        }
        return sum;
    }
    void updatePoint(int i, int val)
    {
        int n = ft.size();
        while (i < n)
        {
            ft[i] += val;
            i += (i & (-i));
        }
    }
    int getcount(int l, int r)
    {
        return getSum(r) - getSum(l - 1);
    }
    void show()
    {
        for (auto i : ft)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<int> arr(n + 1, 0);
    vector<int> count(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == x)
        {
            count[i] = 1;
        }
    }
    FenTree FT = FenTree(count);
    //FT.show();
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int cnt = FT.getcount(l, r);
            if (cnt < k)
            {
                cout << -1 << endl;
                continue;
            }
            int low_count = FT.getSum(l - 1);
            int ans = low_count + k;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                int ll = FT.getSum(l);
                int rr = FT.getSum(r);
                int mm = FT.getSum(mid);
                if (mm == ans)
                {
                    if (l == r)
                    {
                        break;
                    }
                    r = mid;
                }
                else if (mm < ans)
                {
                    l = mid + 1;
                }
                else if (mm > ans)
                {
                    r = mid - 1;
                }
            }
            cout << l << endl;
        }
        else
        {
            int ind, val;
            cin >> ind >> val;
            if (count[ind] == 1 && val != x)
            {
                count[ind] = 0;
                FT.updatePoint(ind, -1);
            }
            else if (count[ind] == 0 && val == x)
            {
                count[ind] = 1;
                FT.updatePoint(ind, 1);
            }
        }
    }
    return 0;
}