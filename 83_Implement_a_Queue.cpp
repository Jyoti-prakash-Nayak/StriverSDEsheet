#include <bits/stdc++.h>
class Queue
{
    int *arr;
    int head;
    int tail;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        size = 10001;
        arr = new int[size];
        head = 0;
        tail = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (head == tail)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (tail == size)
        {
            return;
        }
        else
        {
            arr[tail] = data;
            tail++;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (tail == head)
        {
            return -1;
        }
        else
        {
            int ans = arr[head];
            arr[head] = -1;
            head++;
            if (head == tail)
            {
                head = 0;
                tail = 0;
            }
            return ans;
        }
    }

    int front()
    {
        // Implement the front() function
        if (tail == head)
        {
            return -1;
        }
        else
        {
            return arr[head];
        }
    }
};