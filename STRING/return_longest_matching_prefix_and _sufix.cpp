#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPrefix(string str)
{
    int l = str.length();
    int j = 0;
    int i = 1;
    vector<int> pre_arr(l, 0);
    while (i <= l - 1)
    {
        if (str[i] == str[j])
        {
            pre_arr[i] = j + 1;
            j++;
            i++;
        }
        else
        {
            if (j == 0)
            {
                pre_arr[i] = 0;
                i++;
            }
            else if (j > 0)
            {
                j = pre_arr[j - 1];
            }
        }
    }
    return str.substr(0, pre_arr[l - 1]);
}
