#ifndef NODE_H
#define NODE_H
struct node{
	char data;
	node* next;
	node(char _data, node* _next);
};
#endif
