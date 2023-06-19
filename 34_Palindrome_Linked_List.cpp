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
LinkedListNode<int>* reverse(LinkedListNode<int> *head){
    LinkedListNode<int> *temp=head;
    LinkedListNode<int> *temp1=NULL;
    LinkedListNode<int> *temp2=NULL;

    while(temp!=NULL){
        temp1=temp->next;
        temp->next=temp2;
        temp2=temp;
        temp=temp1;
    }
    head=temp2;
    return head;
}
bool isPalindrome(LinkedListNode<int> *head) {

    // Write your code here.
    if(head==NULL || head->next==NULL)
       return true;
    LinkedListNode<int> *fast=head;
    LinkedListNode<int> *slow=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;

    while(slow!=NULL){
        if(head->data!=slow->data)
           return false;
        head=head->next;
        slow=slow->next;
        
    }
    return true;
}