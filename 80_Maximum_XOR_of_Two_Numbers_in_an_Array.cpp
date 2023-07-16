#include <bits/stdc++.h>
struct Node
{
    Node *link[2];

    bool containsKey(int bit)
    {
        return (link[bit] != NULL);
    }
    Node *get(int bit)
    {
        return link[bit];
    }

    void put(int bit, Node *node)
    {
        link[bit] = node;
    }
};
struct Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        // cout << num << endl;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.
    Trie trie;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        trie.insert(A[i]);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, trie.findMax(A[i]));
    }
    return maxi;
}