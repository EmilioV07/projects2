#ifndef BTNODE_H
#define BTNODE_H
struct btnode{
	char data;
	btnode* left;
	btnode* right;
	btnode* next;
	btnode(char _data, btnode* _left, btnode* _right, btnode* _next);
};
#endif
