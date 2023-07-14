#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{
    // Write your code here.
    int n = price.size();
    vector<int> res;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int ans = 1;
        while (!st.empty() && st.top().first <= price[i])
        {
            ans += st.top().second;
            st.pop();
        }
        res.push_back(ans);
        st.push({price[i], ans});
    }
    return res;
}