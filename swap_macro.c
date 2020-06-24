#include<stdio.h>

#define swap(t,x,y) { 	t z;	\
						z = x; 	\
						x = y;	\
						y = z;  \
					}

int main()
{
	int a = 65;
	int b = 66;
	swap(char,a,b);
	printf("a = %d ,b = %d\n",a,b );
}