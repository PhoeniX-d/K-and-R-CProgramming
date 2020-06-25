#include<stdio.h>
int main()
{
	
	char c;
	while((c = getchar() ) != EOF)
	{
		printf("%d\n",c);
	}
	printf("%d end of file\n",c);
	return 0;
}
