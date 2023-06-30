#include <bits/stdc++.h>
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void f(int ind, string &s, vector<string> &temp, vector<vector<string>> &res)
{
    if (ind == s.size())
    {
        res.push_back(temp);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(ind, i, s))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            f(i + 1, s, temp, res);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    // Write your code here.
    vector<vector<string>> res;
    vector<string> temp;
    f(0, s, temp, res);
    return res;
}