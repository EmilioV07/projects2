#include"node.h"

void enq(node* inputNode, node* curr){//input as (node to enqueue, qHead)
	
	if(curr->next!=nullptr){enq(inputNode, curr->next);}
	else{curr->next=inputNode;return;}
}
node* deq(node* qHead){
	node* next = qHead->next;
	node* curr = qHead;
	qHead = next;
	return curr;
}
