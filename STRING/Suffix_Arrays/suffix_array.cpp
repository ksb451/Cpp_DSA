#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int ll;

vector<int> sort_cyclic_shifts(string const &s)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    {
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        //increase the count of individual charcter
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i - 1];
        //get the cumulative frequency
        for (int i = 0; i < n; i++)
            p[--cnt[s[i]]] = i;
        //sort the character which result in first cyclec sort of 1 charcter

        // for (int i = 0; i < n; i++)
        //     cout << p[i] << " ";
        // cout << "\n";
        c[p[0]] = 0;
        int classes = 0;
        for (int i = 1; i < n; i++) //assign classs to the diff substring
        {
            if (s[p[i]] != s[p[i - 1]])
                classes++;
            c[p[i]] = classes;
        }
    }
    //first iteration is complete

    //now for transition
}

int main()
{
    string s;
    cin >> s;
    sort_cyclic_shifts(s);
    return 0;
}