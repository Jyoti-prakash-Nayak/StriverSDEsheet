/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     Node* temp=head;
     int count=1;
     while(temp->next!=NULL){
          count++;
          temp=temp->next;
     }
     temp->next=head;
     k=k%count;
     k=count-k;
     while(k--){
       temp=temp->next;
     }
     head=temp->next;
     temp->next=NULL;
     return head;
}