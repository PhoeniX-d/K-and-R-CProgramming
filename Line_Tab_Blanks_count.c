#include<stdio.h>
int main()
{
	int c,l1 = 0,t1 = 0,b1 = 0;
	
	while( (c = getchar() ) != EOF)
	{
		if(c == ' ')
		{	
			++b1;
		}
		else if(c == '\n')
		{	
			++l1;
		}
		else if(c == '\t')
		{
			++t1;	
		}
	}
	printf("Lines\t%d\nTabs\t%d\nBlanks\t%d\n",l1,t1,b1);
	return 0;	
}
