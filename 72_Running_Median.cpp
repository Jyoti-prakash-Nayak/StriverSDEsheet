#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < n; i++)
    {
        if (maxi.empty() || maxi.top() >= arr[i])
            maxi.push(arr[i]);
        else
            mini.push(arr[i]);

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

        if (mini.size() < maxi.size())
            cout << maxi.top() << " ";
        else
            cout << (mini.top() + maxi.top()) / 2 << " ";
    }
}