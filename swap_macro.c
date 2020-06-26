<<<<<<< HEAD
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
=======
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
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}