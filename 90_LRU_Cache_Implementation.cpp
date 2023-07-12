#include <bits/stdc++.h>
class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node *node)
    {
        Node *deletePrev = node->prev;
        Node *deleteNext = node->next;
        deletePrev->next = deleteNext;
        deleteNext->prev = deletePrev;
    }

    int get(int key)
    {
        // Write your code here
        if (mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            int res = resNode->val;
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if (mp.find(key) != mp.end())
        {
            Node *del = mp[key];
            mp.erase(key);
            deleteNode(del);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};
