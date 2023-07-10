class Queue
{
    // Define the data members(if any) here.
    stack<int> st1, st2;
    int size = 0;

public:
    Queue()
    {
        // Initialize your data structure here.
        size = 0;
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        while (!st1.empty())
        {
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }
        st1.push(val);
        while (!st2.empty())
        {
            int x = st2.top();
            st2.pop();
            st1.push(x);
        }
        size++;
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (st1.empty())
        {
            return -1;
        }
        else
        {
            int x = st1.top();
            st1.pop();
            size--;
            return x;
        }
    }

    int peek()
    {
        // Implement the peek() function here.
        if (st1.empty())
        {
            return -1;
        }
        return st1.top();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        if (st1.empty())
        {
            return true;
        }
        return false;
    }
};