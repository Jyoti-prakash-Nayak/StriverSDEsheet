#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                res.push_back(temp);
            }
            temp.clear();
        }
    }
    return res;
}