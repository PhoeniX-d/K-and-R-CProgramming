#include<stdio.h>
#define BUFFSIZE  5
#define SIZE	  5

char buf[BUFFSIZE];
int bufp = 0;

int getchX()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetchX(int c)
{
	if(bufp >= BUFFSIZE){
		for(int i = 0;i<BUFFSIZE;i++)
		{
			printf("thats %d\n",buf[i]);
		}
		printf("Ungetch :too many arg\n");
	}
	else 
		buf[bufp++] = c;
}

int isspaceX(char c)
{	
	return (c == ' ' || c == '\t');
}
int isdigitX(char c)
{
	return (c >= '0' && c <= '9');
}

int getint(int *pn)
{
	int c,sign;

	while(isspaceX(c = getchX()))
		;
   
   if(!(isdigitX(c)) && c!=EOF &&  c != '-'  &&  c != '+')
	{
		ungetchX(c);
		return 0;
	}

	sign = (c == '-')? -1 : 1;
	if(c == '+' || c == '-')
		c = getchX();

	for(*pn = 0;isdigitX(c); c = getchX())
		*pn = 10 * (*pn) + (c - '0');

	*pn = (*pn) * sign;

	if(c != EOF)
		ungetchX(c);
	return c;
}

int main()
{
	printf("Inside main\n");
	int array[SIZE],getint(int*);
	for(int i = 0;i < SIZE && (getint(&array[i]) != EOF) ;i++)           
	{
		printf("%d\n",array[i]);
	}
	return 0;
}