#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct TrieNode
{
    int num;//contains the no of words contain within this link
    TrieNode* child[26];//al tha links
    bool isendofword;//is it a end of word
    TrieNode()//constructor
    {
        num=0;
        for(int i=0;i<26;i++)//initlize all links to null
        {
            child[i]=NULL;
        }
        isendofword=false;
    }
};

void add(TrieNode* root, string str)
{
    TrieNode* temp=root;//create a temp node to traverse down
    for(int i=0;i<str.length();i++)//for each letter in the string
    {
        if(temp->child[str[i]-'a']==NULL)//if link not exist
        {
            temp->child[str[i]-'a']=new TrieNode();//create link
        }
        temp->num++;//increse no of words below this links
        temp=temp->child[str[i]-'a'];//go to the link
    }
    temp->isendofword=true;//when loop ends at the last node mark the endofword. Some implementation contains weight or value at the last node.
}
string getprefix(TrieNode* root, string str)
{
    TrieNode* temp=root;
    string pre;
    for(int i=0;i<str.length();i++)
    {
        pre.push_back(str[i]);
        if(temp->child[str[i]-'a']!=NULL)
        {
            temp=temp->child[str[i]-'a'];
        }
        if(temp->num==1)
        {
            break;
        }
    }
    return pre;
}

