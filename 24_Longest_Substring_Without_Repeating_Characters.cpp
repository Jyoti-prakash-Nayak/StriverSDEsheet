#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    vector<int> res(26, 0);
    int n = input.size();
    int j = 0;
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        res[input[i] - 'a']++;
        while (res[input[i] - 'a'] > 1)
        {
            res[input[j] - 'a']--;
            j++;
        }
        maxi = max(maxi, i - j + 1);
    }
    return maxi;
}