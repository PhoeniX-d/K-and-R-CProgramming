#include<stdio.h>
#define NOBLANK 'q'
int main()
{
	int c;
	char lastc = NOBLANK;
	while((c = getchar()) != EOF)
	{
		if(c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
	return 0;
}