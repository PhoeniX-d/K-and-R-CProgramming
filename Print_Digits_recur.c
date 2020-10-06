#include <stdio.h>

void printd(int no);
int main()
{
	int no = 0;
	printf("Enter the number\n");
	scanf("%d", &no);

	printd(no);
	return 0;
}

void printd(int n)
{
	if (n < 0)
	{
		// /putchar('-');
		n = -n;
	}
	printf("%d ", (n % 10));
	if (n / 10)
	{

		printd(n / 10);
	}
}