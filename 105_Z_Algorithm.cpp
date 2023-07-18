#include <bits/stdc++.h>
int zAlgorithm(string s, string p, int n, int m)
{
    // Write your code here
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (j < n)
    {
        if (j - i + 1 < m)
        {
            j++;
        }
        else if (j - i + 1 == m)
        {
            if (s.substr(i, j - i + 1) == p)
            {
                cnt++;
            }
            i++;
            j++;
        }
    }
    return cnt;
}