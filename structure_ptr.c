<<<<<<< HEAD
<<<<<<< HEAD
=======
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
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
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
<<<<<<< HEAD
=======
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
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}