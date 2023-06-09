#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*>mp;
    LinkedListNode<int>* temp=head;

    while(temp!=NULL){
        mp[temp]=new LinkedListNode<int>(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
      mp[temp]->next=mp[temp->next];
      mp[temp]->random=mp[temp->random];
      temp=temp->next;
    }
    return mp[head];
}
