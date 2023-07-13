#include <bits/stdc++.h>
// Implement class for minStack.
class minStack
{
    // Write your code here.

public:
    vector<pair<int, int>> res;

    // Constructor
    minStack()
    {
        // Write your code here.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        // Write your code here.
        if (res.empty())
            res.push_back({num, num});
        else
            res.push_back({num, min(num, res.back().second)});
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (res.empty())
            return -1;
        int val = res.back().first;
        res.pop_back();
        return val;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        // Write your code here.
        if (res.empty())
            return -1;
        return res.back().first;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        // Write your code here.
        if (res.empty())
            return -1;
        return res.back().second;
    }
};