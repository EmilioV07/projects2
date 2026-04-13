#include"node.h"
#include<iostream>
void enq(node* inputNode, node*& curr){//input as (node to enqueue, qHead)
	if(curr==nullptr){
		curr=inputNode;
		std::cout<<"Added "<<inputNode->data<<std::endl;
		return;
	}
	else if(curr->next==nullptr){
		curr->next=inputNode;
		std::cout<<"Added "<<inputNode->data<<std::endl;
		//enq(inputNode, curr->next);
	}
	else{enq(inputNode, curr->next);}
}
node* deq(node*& qHead){
	if(qHead==nullptr){return nullptr;}//empty queue friendly checks added later
	//node* next = qHead->next;
	node* curr = qHead;
	qHead = qHead->next;
	curr->next = nullptr;//cleans dequeued node
	return curr;//returns top of list, which works because we add at the bottom
}
