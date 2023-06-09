#include <bits/stdc++.h>
double median(vector<int> &nums1, vector<int> &nums2)
{
    // Write your code here.
    if (nums1.size() > nums2.size())
    {
        swap(nums1, nums2);
    }
    int n = nums1.size();
    int m = nums2.size();
    int begin = 0;
    int end = n;
    while (begin <= end)
    {
        int i1 = (begin + end) / 2;
        int i2 = (n + m + 1) / 2 - i1;

        int min1 = (i1 == n) ? INT_MAX : nums1[i1];
        int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];

        int min2 = (i2 == m) ? INT_MAX : nums2[i2];
        int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];

        if ((max1 <= min2) && (max2 <= min1))
        {
            if ((n + m) % 2 == 0)
            {
                return ((double)(max(max1, max2) + min(min1, min2)) / 2);
            }
            else
            {
                return ((double)max(max1, max2));
            }
        }
        else if (max1 > min2)
        {
            end = i1 - 1;
        }
        else
        {
            begin = i1 + 1;
        }
    }
    return 0.0;
}