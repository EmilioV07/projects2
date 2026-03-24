#ifndef Q_H
#define Q_H
struct q{
	q* next;
	int num;
	q(int _num, q* _next);
};
#endif
