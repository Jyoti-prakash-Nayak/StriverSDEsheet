#include <bits/stdc++.h>
string check(string &str, int l, int h, int n)
{
    while (l >= 0 && h <= n)
    {
        if (str[l] != str[h])
        {
            break;
        }
        l--;
        h++;
    }
    return str.substr(l + 1, h - l - 1);
}
string longestPalinSubstring(string str)
{
    // Write your code here.
    int n = str.size();
    string res = "";

    for (int i = 0; i < n; i++)
    {
        string odd = check(str, i - 1, i + 1, n);
        if (odd.size() > res.size())
        {
            res = odd;
        }
    }

    for (int i = 0; i < n; i++)
    {
        string even = check(str, i - 1, i, n);
        if (even.size() > res.size())
        {
            res = even;
        }
    }
    return res;
}