#include <bits/stdc++.h>
int singleNonDuplicate(vector<int> &arr)
{
    // Write your code here
    int low = 0;
    int high = arr.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 != 0 && arr[mid] == arr[mid - 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return arr[low];
}