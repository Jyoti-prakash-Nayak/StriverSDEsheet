#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
    int n;
    int *arr;
    int topo;
    Stack(int capacity)
    {
        // Write your code here.
        arr = new int[capacity];
        n = capacity;
        topo = -1;
    }

    void push(int num)
    {
        // Write your code here.
        if (topo != n - 1)
            arr[++topo] = num;
    }

    int pop()
    {
        // Write your code here.
        if (topo != -1)
        {
            int ans = arr[topo];
            topo--;
            return ans;
        }
        else
            return -1;
    }

    int top()
    {
        // Write your code here.
        if (topo != -1)
            return arr[topo];
        else
            return -1;
    }

    int isEmpty()
    {
        // Write your code here.
        return topo == -1 ? 1 : 0;
    }

    int isFull()
    {
        // Write your code here.
        return topo == n - 1 ? 1 : 0;
    }
};