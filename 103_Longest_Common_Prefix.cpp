#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code hereart
    sort(arr.begin(), arr.end());
    string start = arr[0];
    string end = arr[n - 1];

    string ans = "";
    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] == end[i])
        {
            ans += start[i];
        }
        else
            break;
    }
    return ans;
}
