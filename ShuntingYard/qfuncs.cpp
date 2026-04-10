#include"node.h"
#include<iostream>
void enq(node* inputNode, node* curr){//input as (node to enqueue, qHead)
	if(curr==nullptr){curr=inputNode; std::cout<<"Added "<<inputNode->data<<std::endl; return;}
	else{enq(inputNode, curr->next);}
}
node* deq(node* qHead){
	node* next = qHead->next;
	node* curr = qHead;
	qHead = next;
	return curr;
}
