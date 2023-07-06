#include <bits/stdc++.h>
double multi(int num, int n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * num;
    }
    return ans;
}
int NthRoot(int n, int m)
{
    // Write your code here.
    int low = 1;
    int high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        double f = multi(mid, n);
        if (f == m)
        {
            return mid;
        }
        else if (f < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}