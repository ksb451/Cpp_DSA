#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int i, int j, int cost)
{
    if (i >= j)
        return 0;
    int min2 = INT_MAX;

    for (int k = i + 1; k <= j; k++)
    {
        int one = 0, two = 0;
        map<int, int> m1, m2;
        for (int l = i; l < k; l++)
            m1[arr[l]]++;
        for (int l = k; l <= j; l++)
            m2[arr[l]]++;
        for (auto o : m1)
            if (o.second > 1)
                one += o.second;
        for (auto o : m2)
            if (o.second > 1)
                two += o.second;

        int m = solve(arr, i, k - 1, cost);
        int r = solve(arr, k, j, cost);
        cout << m << " " << r << " " << i << " " << j << endl;
        int temp = m + r + (cost * 2) + two + one;
        if (temp < min2)
            min2 = temp;
    }
    return min2;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(arr, 0, n - 1, k) << endl;
    }
}