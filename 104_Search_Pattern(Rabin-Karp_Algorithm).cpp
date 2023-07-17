#include <bits/stdc++.h>
vector<int> stringMatch(string text, string pattern)
{
    // Write your code here.
    vector<int> res;
    int i = 0;
    int j = 0;
    int k = pattern.size();
    int n = text.size();

    while (j < n)
    {
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (text.substr(i, j - i + 1) == pattern)
            {
                res.push_back(i + 1);
            }
            i++;
            j++;
        }
    }
    return res;
}
