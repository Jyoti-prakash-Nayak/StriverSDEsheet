#include <bits/stdc++.h>
struct Node
{
    Node *link[26];

    bool containsKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
};
int distinctSubstring(string &word)
{
    //  Write your code here.
    int cnt = 0;
    Node *root = new Node();
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(word[j]))
            {
                cnt++;
                node->put(word[j], new Node());
            }
            node = node->get(word[j]);
        }
    }
    return cnt;
}
