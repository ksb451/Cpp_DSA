#include <iostream>
#include <vector>
using namespace std;

typedef long long int lld;

int getsum(vector<int> &bittree, int index)
{
    lld sum = 0;
    index++;
    while (index > 0)
    {
        sum += bittree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(vector<int> &bittree, int index, int val)
{
    index++;
    while (index < bittree.size())
    {
        bittree[index] += val;
        index += index & (-index);
    }
}

vector<int> constructBITTree(vector<int> &arr)
{
    int n = arr.size();
    vector<int> bittree(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        updateBIT(bittree, i, arr[i]);
    }
    return bittree;
}