#ifndef Q_H
#define Q_H
struct stk{
	stk* next;
	int num;
	stk(int _num, stk* _next);
};
#endif
