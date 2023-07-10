bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else if (!st.empty() && s[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
        else if (!st.empty() && s[i] == ']' && st.top() == '[')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}