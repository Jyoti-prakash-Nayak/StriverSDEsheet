#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    list<int> l;
    vector<int> res;
    int i = 0;
    int j = 0;

    while (j < nums.size())
    {
        while (!l.empty() && l.back() < nums[j])
        {
            l.pop_back();
        }

        l.push_back(nums[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            res.push_back(l.front());

            if (l.front() == nums[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return res;
}