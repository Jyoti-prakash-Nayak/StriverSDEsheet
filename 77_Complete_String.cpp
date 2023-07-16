#include <bits/stdc++.h>
struct Node
{
    Node *link[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool chackIfPrefixExit(string word)
    {
        Node *node = root;
        bool flag = true;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                flag = flag & node->isEnd();
            }
            else
                return false;
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie *obj = new Trie();
    for (auto it : a)
    {
        obj->insert(it);
    }

    string longest = "";
    for (auto it : a)
    {
        if (obj->chackIfPrefixExit(it))
        {
            if (it.size() > longest.size())
            {
                longest = it;
            }
            else if (it.size() == longest.size() && it < longest)
            {
                longest = it;
            }
        }
    }
    if (longest == "")
        return "None";
    return longest;
}