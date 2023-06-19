#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    if(head==NULL || head->next==NULL){
		return head;
	}
	
	Node* dummy=new Node(0);
	dummy->next=head;

	Node* curr=dummy;
	Node* nex=dummy;
	Node* prev=dummy;

	for(int i=0;i<n;i++){
		int k=b[i];
		if(k==0)
		   continue;
		if(k==1){
			prev=prev->next;
			continue;
		}
		
		
		curr=prev->next;
		nex=curr->next;
		for(int j=1;j<k;j++){
			 if(nex == NULL)
                 return dummy->next;
			curr->next=nex->next;
			nex->next=prev->next;
			prev->next=nex;
			nex=curr->next;
		}
		prev=curr;
		if(nex==NULL){
			return dummy->next;
		}
	}
    return dummy->next;
	
}