#include <bits/stdc++.h>
void f(int ind, string &s, vector<string> &res)
{
    if (ind == s.size())
    {
        res.push_back(s);
        return;
    }

    for (int i = ind; i < s.size(); i++)
    {
        swap(s[i], s[ind]);
        f(ind + 1, s, res);
        swap(s[i], s[ind]);
    }
}
vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> ans;
    f(0, s, ans);
    return ans;
}