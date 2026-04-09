#ifndef BTNODE_H
#define BTNODE_H
struct btnode{
	int data;
	btnode* left;
	btnode* right;
	btnode(int _data, btnode* left = nullptr, btnode* right = nullptr);
};
#endif
