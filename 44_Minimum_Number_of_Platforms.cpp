#include <bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);

    int plat = 1;
    int i = 1;
    int j = 0;
    while (i < n)
    {
        if (at[i] <= dt[j])
        {
            plat++;
        }
        else
        {
            j++;
        }
        i++;
    }
    return plat;
}