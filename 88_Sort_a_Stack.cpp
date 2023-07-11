#include <bits/stdc++.h>
void insert(stack<int> &st, int num)
{
    if (st.empty())
    {
        st.push(num);
        return;
    }

    if (st.top() <= num)
    {
        st.push(num);
        return;
    }

    int x = st.top();
    st.pop();

    insert(st, num);
    st.push(x);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    sortStack(stack);
    insert(stack, num);
}