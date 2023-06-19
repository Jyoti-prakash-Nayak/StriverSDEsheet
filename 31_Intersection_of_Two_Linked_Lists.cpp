/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include<bits/stdc++.h>
Node* findIntersection(Node *headA, Node *headB)
{
     Node *temp=headA;
   Node * ptr=headB;
        
        if(temp==NULL || ptr==NULL){
            return NULL;
        }
        
        while(temp!=ptr){
            if(temp==ptr)
              return ptr;
            
            if(temp==NULL){
                temp=headB;
            }
            else{
                temp=temp->next;
            }
            if(ptr==NULL){
                ptr=headA;
            }
            else{
                ptr=ptr->next;
            }
        }
        return ptr;
}