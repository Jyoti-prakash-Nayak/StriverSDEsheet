#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> st;
    for (auto it : arr)
    {
        st.insert(it);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i] - 1) != st.end())
        {
            continue;
        }
        else
        {
            int count = 0;
            int curr = arr[i];
            while (st.find(curr) != st.end())
            {
                count++;
                curr++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}