#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct TrieNode
{
    bool isendofword;
    TrieNode *child[26];
    TrieNode()
    {
        isendofword = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

void add(TrieNode *root, string str)
{
    TrieNode *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        if (temp->child[str[i] - 'a'] == NULL)
        {
            temp->child[str[i] - 'a'] = new TrieNode();
        }
        temp = temp->child[str[i] - 'a'];
    }
    temp->isendofword = true;
}

bool search(TrieNode *root, string str)
{
    TrieNode *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        if (temp->child[str[i] - 'a'] == NULL)
        {
            return false;
        }
        temp = temp->child[str[i] - 'a'];
    }
    if (temp->isendofword)
    {
        return true;
    }
    return false;
}

bool compareindex(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return false;
}

vector<int> solve(string A, vector<string> &B)
{
    stringstream ss(A);
    vector<int> ans;
    TrieNode *root = new TrieNode();
    while (ss.good())
    {
        string word;
        getline(ss, word, '_');
        //cout<<word<<" ";
        if (word.length())
            add(root, word);
    }
    vector<pair<int, int>> index_rating;
    for (int i = 0; i < B.size(); i++)
    {
        //cout<<B[i].length()<<" ";
        int n = 0;
        stringstream ssa(B[i]);
        while (ssa.good())
        {
            string word1;
            getline(ssa, word1, '_');
            //cout<<word1<<" ";
            if (word1.length())
            {
                if (search(root, word1))
                {
                    n++;
                }
            }
        }
        //cout<<n<<" ";
        pair<int, int> a = make_pair(i, n);
        index_rating.push_back(a);
    }
    sort(index_rating.begin(), index_rating.end(), compareindex);
    for (int i = 0; i < index_rating.size(); i++)
    {
        ans.push_back(index_rating[i].first);
    }
    return ans;
}
