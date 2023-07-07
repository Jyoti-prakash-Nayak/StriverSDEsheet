#include <bits/stdc++.h>
bool isPossible(int n, int m, vector<int> &time, long long int mid)
{
    long long int count = 1;
    long long int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (sum + time[i] <= mid)
        {
            sum += time[i];
        }
        else
        {
            count++;
            if (count > n || time[i] > mid)
            {
                return false;
            }
            else
            {
                sum = time[i];
            }
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long int s = 0;
    long long int sum = 0;
    for (int i = 0; i < time.size(); i++)
    {
        sum += time[i];
    }

    long long int e = sum;
    long long int ans = -1;

    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        if (isPossible(n, m, time, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}