#include <bits/stdc++.h>
string reverseString(string &str)
{
    // Write your code here.
    stack<string> st;
    string temp;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            temp += str[i];
        }
        if (str[i] == ' ' || i == str.size() - 1)
        {
            if (temp.size() != 0)
            {
                st.push(temp);
                temp.clear();
            }
        }
    }

    string res;
    while (!st.empty())
    {
        res += st.top();
        st.pop();
        if (st.size() != 0)
        {
            res += ' ';
        }
    }
    return res;
}