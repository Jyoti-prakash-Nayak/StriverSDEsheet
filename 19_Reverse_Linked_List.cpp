#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* temp=head;
    LinkedListNode<int>* temp1=NULL;
    LinkedListNode<int>* temp2=NULL;

    while(temp!=NULL){
        temp1=temp->next;
        temp->next=temp2;
        temp2=temp;
        temp=temp1;
    }
    head=temp2;
    return head;
}