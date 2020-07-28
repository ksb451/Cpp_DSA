#include <iostream>
#include <vector>
using namespace std;

typedef long long int lld;

// int getsum(vector<int> &bittree, int index)
// {
//     lld sum = 0;
//     index++;
//     while (index > 0)
//     {
//         sum += bittree[index];
//         index -= index & (-index);
//     }
//     return sum;
// }

// void updateBIT(vector<int> &bittree, int index, int val)
// {
//     index++;
//     while (index < bittree.size())
//     {
//         bittree[index] += val;
//         index += index & (-index);
//     }
// }

// vector<int> constructBITTree(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> bittree(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         updateBIT(bittree, i, arr[i]);
//     }
//     return bittree;
// }

// void makeBITTree(vector<int> &arr)
// {
//     int n = arr.size();
//     for (int i = 1; i <= n; i++)
//     {
//         int parent = i + (i & (-i));
//         if (parent <= n)
//         {
//             arr[parent - 1] += arr[i - 1];
//         }
//     }
// }

// void show(vector<int> arr)
// {
//     for (auto i : arr)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
// }

class FenTree
{
    vector<int> ft;

public:
    FenTree(vector<int> &arr) //O(n) construction by cloning the array first
    {
        int n = arr.size();
        ft = {0}; //to make the array 1 based
        ft.insert(ft.end(), arr.begin(), arr.end());
        for (int i = 1; i <= n; i++) //this loop propagets the effect all tha way upto the tree
        {
            int parent = i + (i & (-i)); //the immediate parent responsible for this child
            if (parent <= n)
            {
                ft[parent] += ft[i]; //update the immediate parent
            }
        }
    }
    int getSum(int index)
    {
        index++; //input is zero based and the Fenwicktree is 1 based
        int sum = 0;
        while (index > 0) //go all the way up to the tree
        {
            sum += ft[index];
            index -= (index & (-index)); //get child
        }
        return sum;
    }
    void updateIndex(int index, int val)
    {
        index++;
        while (index < ft.size()) //go all the way down to the leaf
        {
            ft[index] += val;
            index += index & (-index); //get child
        }
    }
    int rangeQuery(int i, int j) //sum of i and j included
    {
        return getSum(j) - getSum(i - 1);
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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int &i : arr)
        {
            cin >> i;
        }
        //vector<int> ft1 = constructBITTree(arr);
        FenTree ft2 = FenTree(arr);
        //makeBITTree(arr);
        //show(ft1);
        //show(arr);
        ft2.show();
        cout << ft2.rangeQuery(1, 3) << endl;

        cout << ft2.rangeQuery(2, 3) << endl;

        ft2.updateIndex(2, 1);

        cout << ft2.rangeQuery(1, 4) << endl;
    }
    return 0;
}