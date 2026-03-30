#ifndef BTN_H
#define BTN_H
struct btnode{
	int data;
	btnode* left;
	btnode* right;
	btnode(int _data, btnode* left = nullptr, btnode* right = nullptr);
};
#endif
