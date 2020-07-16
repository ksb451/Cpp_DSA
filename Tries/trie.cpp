#include <iostream>
#include <string>
#include <vector>
using namespace std;
// struct TrieNode
// {
//     int num;             //contains the no of words contain within this link
//     TrieNode *child[26]; //al tha links
//     bool isendofword;    //is it a end of word
//     TrieNode()           //constructor
//     {
//         num = 0;
//         for (int i = 0; i < 26; i++) //initlize all links to null
//         {
//             child[i] = NULL;
//         }
//         isendofword = false;
//     }
// };

// void add(TrieNode *root, string str)
// {
//     TrieNode *temp = root;                 //create a temp node to traverse down
//     for (int i = 0; i < str.length(); i++) //for each letter in the string
//     {
//         if (temp->child[str[i] - 'a'] == NULL) //if link not exist
//         {
//             temp->child[str[i] - 'a'] = new TrieNode(); //create link
//         }
//         temp->num++;                      //increse no of words below this links
//         temp = temp->child[str[i] - 'a']; //go to the link
//     }
//     temp->isendofword = true; //when loop ends at the last node mark the endofword. Some implementation contains weight or value at the last node.
// }
// string getprefix(TrieNode *root, string str)
// {
//     TrieNode *temp = root;
//     string pre;
//     for (int i = 0; i < str.length(); i++)
//     {
//         pre.push_back(str[i]);
//         if (temp->child[str[i] - 'a'] != NULL)
//         {
//             temp = temp->child[str[i] - 'a'];
//         }
//         if (temp->num == 1)
//         {
//             break;
//         }
//     }
//     return pre;
// }

struct TrieNode
{
    int words;
    int prefixes;
    TrieNode *child[26];
    TrieNode()
    {
        words = 0;
        prefixes = 0;
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
        temp->prefixes++;
        temp = temp->child[str[i] - 'a'];
    }
    temp->prefixes++;
    temp->words++;
}

int count_words(string word, TrieNode *root)
{
    TrieNode *temp = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (temp->child[word[i] - 'a'] == NULL)
        {
            return 0;
        }
        else
        {
            temp = temp->child[word[i] - 'a'];
        }
    }
    return temp->words;
}

int count_prefixses(string pre, TrieNode *root)
{
    TrieNode *temp = root;
    for (int i = 0; i < pre.length(); i++)
    {
        if (temp->child[pre[i] - 'a'] == NULL)
        {
            return 0;
        }
        else
        {
            temp = temp->child[pre[i] - 'a'];
        }
    }
    return temp->prefixes;
}

string get_unique_prefix(string word, TrieNode *root)
{
    TrieNode *temp = root;
    string pre;
    for (int i = 0; i < word.length(); i++)
    {
        if (temp->child[word[i] - 'a'] == NULL)
        {
            return string();
        }
        else
        {
            pre.push_back(word[i]);
            temp = temp->child[word[i] - 'a'];
        }
        if (temp->prefixes == 1)
        {
            return pre;
        }
    }
    return pre;
}