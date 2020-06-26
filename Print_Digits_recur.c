<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<stdio.h>

void printd(int no);
int main()
{
	int no = 0;
	printf("Enter the number\n");
	scanf("%d",&no);

	printd(no);
	return 0;
}

void printd(int n)
{
	if(n < 0)
	{
		// /putchar('-');
		n = -n;
	}
	printf("%d ",(n % 10));
	if(n/10)
	{

		printd(n/10);
	}
	
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
#include<stdio.h>

void printd(int no);
int main()
{
	int no = 0;
	printf("Enter the number\n");
	scanf("%d",&no);

	printd(no);
	return 0;
}

void printd(int n)
{
	if(n < 0)
	{
		// /putchar('-');
		n = -n;
	}
	printf("%d ",(n % 10));
	if(n/10)
	{

		printd(n/10);
	}
	
<<<<<<< HEAD
=======
#include<stdio.h>

void printd(int no);
int main()
{
	int no = 0;
	printf("Enter the number\n");
	scanf("%d",&no);

	printd(no);
	return 0;
}

void printd(int n)
{
	if(n < 0)
	{
		// /putchar('-');
		n = -n;
	}
	printf("%d ",(n % 10));
	if(n/10)
	{

		printd(n/10);
	}
	
=======
>>>>>>> 79b9204c7406d7d4515b4727f61083bd8a6eb919
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}