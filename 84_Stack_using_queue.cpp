class Stack
{
    // Define the data members.

public:
    queue<int> q;
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return q.size() == 0;
    }

    void push(int element)
    {
        // Implement the push() function.
        q.push(element);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (isEmpty())
        {
            return -1;
        }
        int ans = top();

        q.pop();
        return ans;
    }

    int top()
    {
        // Implement the top() function.
        if (!q.empty())
        {
            return q.front();
        }
        return -1;
    }
};