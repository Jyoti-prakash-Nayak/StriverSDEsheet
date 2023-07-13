#include <bits/stdc++.h>
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
    stack<int> st;
    int maxi = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxi = max(maxi, height * width);
        }
        st.push(i);
    }
    return maxi;
}