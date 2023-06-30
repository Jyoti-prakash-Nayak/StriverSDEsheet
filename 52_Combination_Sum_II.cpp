#include <bits/stdc++.h>
void f(int ind, int target, int n, vector<int> &arr, vector<int> &temp, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (i == ind || arr[i] != arr[i - 1])
        {
            if (target >= arr[i])
            {
                temp.push_back(arr[i]);
                f(i + 1, target - arr[i], n, arr, temp, res);
                temp.pop_back();
            }
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    f(0, target, n, arr, temp, res);
    sort(res.begin(), res.end());
    return res;
}
