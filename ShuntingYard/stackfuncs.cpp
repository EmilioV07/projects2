#include"node.h"
#include<iostream>
void push(node* inputNode, node*& stackHead){//add a node to the top of the stack given "_data" (from input string)
	if(stackHead!=nullptr){//if stack is not empty (call first to avoid redundant check)
		inputNode->next=stackHead;
		stackHead=inputNode;
		return;
	}
	else{//if stack is empty
		stackHead=inputNode;
		return;
	}
}
node* pop(node*& stackHead){//return a pointer to the top item after removing it from the stack
	if(stackHead==nullptr){return nullptr;}
	node* holder = stackHead;//store head/top of list
	stackHead=stackHead->next;//move head pointer to node underneath
	holder->next=nullptr;//clean node
	return holder;
}
void peek(node* stackHead){
	std::cout<<stackHead->data<<std::endl;
	return;
}
