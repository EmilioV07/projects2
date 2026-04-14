#include"btnode.h"
btnode::btnode(int _data, btnode* _left, btnode* _right, btnode* _next){
	data = _data;
	left = _left;
	right = _right;
	next = _next;
}
