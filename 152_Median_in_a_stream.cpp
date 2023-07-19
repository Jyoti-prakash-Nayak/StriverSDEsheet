#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n)
{
    // Write your code here
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (maxi.empty() || arr[i] < maxi.top())
        {
            maxi.push(arr[i]);
        }
        else
        {
            mini.push(arr[i]);
        }

        if (maxi.size() > mini.size() + 1)
        {
            mini.push(maxi.top());
            maxi.pop();
        }
        else if (maxi.size() < mini.size())
        {
            maxi.push(mini.top());
            mini.pop();
        }

        if (maxi.size() > mini.size())
            res.push_back(maxi.top());
        else
            res.push_back((maxi.top() + mini.top()) / 2);
    }
    return res;
}
