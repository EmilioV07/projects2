#include"btnode.h"
btnode::btnode(char _data, btnode* _left, btnode* _right, btnode* _next){
	data = _data;
	left = _left;
	right = _right;
	next = _next;
}
