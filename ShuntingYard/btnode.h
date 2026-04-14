#ifndef BTNODE_H
#define BTNODE_H
struct btnode{
	int data;
	btnode* left;
	btnode* right;
	btnode* next;
	btnode(int _data, btnode* left = _left, btnode* right = _right, btnode* next = _next);
};
#endif
