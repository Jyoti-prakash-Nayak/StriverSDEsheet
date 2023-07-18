#include <bits/stdc++.h>
bool check(int i, int j, string &str)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int minCharsforPalindrome(string str)
{
    // Write your code here.
    int n = str.size();
    int i = n - 1;

    while (i > 0)
    {
        if (str[i] == str[0])
        {
            if (check(0, i, str))
            {
                return n - i - 1;
            }
        }
        i--;
    }
    return n - 1;
}
