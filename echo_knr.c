#include<stdio.h>

int main(int argc,char** argv)
{
	while(argc > 1)
	{
		printf("%s%s",*++argv,(argc > 1)?" ":"");
		argc--;
	}
	printf("\n");
	return 0;
}