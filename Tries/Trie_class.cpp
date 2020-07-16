#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Trie
{
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
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void add(std::string str)
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

    void add(std::vector<std::string> &list)
    {
        for (auto i : list)
            add(i);
    }

    int count_words(std::string word)
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

    int count_prefixses(std::string pre)
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

    std::string get_unique_prefix(std::string word)
    {
        TrieNode *temp = root;
        std::string pre;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->child[word[i] - 'a'] == NULL)
            {
                return std::string();
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
};

int main()
{
    std::vector<std::string> list = {"keshab", "raghab", "keshty", "qwerty", "numbers"};
    Trie dict;
    dict.add(list);
    std::cout << dict.count_words("keshab") << std::endl;
    dict.add("keshab");
    std::cout << dict.count_words("keshab") << std::endl;
    std::cout << dict.get_unique_prefix("keshab");
    return 0;
}