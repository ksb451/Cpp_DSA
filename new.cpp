#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMinInsertions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY firstArray
 *  2. INTEGER_ARRAY secondArray
 */

int query(int *tree, int treenode, int l, int r, int s, int e)
{
    if (l > r)
        return 0;
    int mid = (l + r) / 2;
    if (s > r || e < l)
        return 0;
    if (s <= l && r <= e)
        return tree[treenode];
    return max(query(tree, 2 * treenode + 1, l, mid, s, e), query(tree, 2 * treenode + 2, mid + 1, r, s, e));
}

void update(int *tree, int treenode, int l, int r, int i, int val)
{
    if (l > r)
        return;
    if (l == r)
    {
        tree[treenode] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
    {
        update(tree, 2 * treenode + 1, l, mid, i, val);
    }
    else
    {
        update(tree, 2 * treenode + 2, mid + 1, r, i, val);
    }
    tree[treenode] = max(tree[2 * treenode + 1], tree[2 * treenode + 2]);
}

int getMinInsertions(vector<int> firstArray, vector<int> secondArray)
{
    int n = firstArray.size();
    int m = secondArray.size();

    vector<int> find(m, 0);

    unordered_map<int, int> f;
    for (int i = 0; i < m; i++)
        f[secondArray[i]] = i;

    int *tree = new int[4 * m]();

    for (int i = n - 1; i >= 0; i--)
    {
        int a = firstArray[i];
        if (f.count(a) > 0)
        {
            int j = f[a];
            int q = query(tree, 0, 0, m - 1, j + 1, m - 1);
            if (q + 1 > find[j])
            {
                find[j] = q + 1;
                update(tree, 0, 0, m - 1, j, find[j]);
            }
        }
    }
    int max_seq = 0;
    for (int i = 0; i < m; i++)
        max_seq = max(max_seq, find[i]);

    return m - max_seq;
}

int main()