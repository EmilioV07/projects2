#include"node.h"
#include<iostream>
void push(int _data, node* stackHead){//add a node to the top of the stack given "_data" (from input string)
	node* n = new node(_data, nullptr);
	if(stackHead!=nullptr){//if stack is not empty (call first to avoid redundant check)
		n->next=stackHead;
		stackHead=n;
		return;
	}
	else{//if stack is empty
		stackHead=n;
		return;
	}
}
node* pop(node* stackHead){//return a pointer to the top item after removing it from the stack
	node* holder = stackHead;//store head
	stackHead=stackHead->next;//move head pointer to node underneath
	holder->next=nullptr;//clean node
	return holder;
}
void peek(node* stackHead){
	std::cout<<stackHead->data<<std::endl;
	return;
}
