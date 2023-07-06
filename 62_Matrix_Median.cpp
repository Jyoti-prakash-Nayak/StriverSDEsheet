#include <bits/stdc++.h>
int findVal(vector<vector<int>> &matrix, int i, int val)
{
    int l = 0;
    int r = matrix[0].size() - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (matrix[i][m] <= val)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 1;
    int high = 1e5;
    int N = n * m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += findVal(matrix, i, mid);
        }
        if (count <= N / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}