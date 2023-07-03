#include <bits/stdc++.h>
void f(int ind, string &s, string str, set<string> &st, vector<string> &res)
{
    if (ind == s.size())
    {
        str.pop_back();
        res.push_back(str);
        return;
    }
    string temp = "";
    for (int i = ind; i < s.size(); i++)
    {
        temp.push_back(s[i]);
        if (st.count(temp))
        {
            f(i + 1, s, str + temp + " ", st, res);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    set<string> st;
    for (auto it : dictionary)
    {
        st.insert(it);
    }

    vector<string> res;
    f(0, s, "", st, res);
    return res;
}
