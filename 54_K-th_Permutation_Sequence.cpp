#include <bits/stdc++.h>
string kthPermutation(int n, int k)
{
    // Write your code here.
    vector<int> num;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);

    k = k - 1;
    string ans = "";
    while (true)
    {
        ans = ans + to_string(num[k / fact]);
        num.erase(num.begin() + k / fact);
        if (num.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / num.size();
    }
    return ans;
}
