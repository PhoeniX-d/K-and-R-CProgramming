#include<stdio.h>
#define MAX 
struct demo
{
	int   len;
	char* str;
};

int main()	
{
	struct demo d,*p; 
	p = &d;
	p->len = MAX;
	*(p->str) = 'A';

	printf(" initially len = %d\n",p->len);
	printf(" initially str = %c\n",*p->str);
	++(*p->str);
	printf(" initially str = %c\n",(*p->str)++);
	printf(" initially str = %c\n",(*p->str)++);
	return 0;
}