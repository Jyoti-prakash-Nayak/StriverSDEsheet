#include <bits/stdc++.h>
int atoi(string str)
{
    // Write your code here.
    bool flag = false;
    int start = 0;
    if (str[0] == '-')
    {
        start = 1;
        flag = true;
    }
    int ans = 0;
    for (int i = start; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            ans = ans * 10 + (str[i] - '0');
        }
    }
    if (flag == true)
    {
        ans *= -1;
    }

    return ans;
}