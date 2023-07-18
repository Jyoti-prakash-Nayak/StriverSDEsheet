#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    // Write your code here.
    int n = str1.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[str1[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp.find(str2[i]) != mp.end())
        {
            mp[str2[i]]--;
        }
        else
        {
            return false;
        }
    }
    return true;
}